/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:14:49 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/14 19:30:19 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include "tokenizer.h"
#include <stdlib.h>

void	*unexpected_token(const char *token)
{
	t_string	msg;

	msg = ft_str_new(NULL);
	ft_str_append_cstr(msg, "syntax error near unexpected token \'");
	ft_str_append_cstr(msg, token);
	ft_str_add_back(msg, '\'');
	print_error(ft_str_data(msg));
	ft_str_free(msg);
	return (NULL);
}

void	init_tokenizer(t_tokenizer *tok)
{
	tok->cursor = 0;
	tok->state = TEXT;
	tok->next_token = NULL;
}

bool	get_operator_token(t_tokenizer *tok)
{
	t_string	token;
	char		first_char;

	token = ft_str_new(NULL);
	first_char = cursor_char(tok);
	ft_str_add_back(token, first_char);
	inc_cursor(tok);
	if (ft_strchr("<>", first_char) && first_char == cursor_char(tok))
	{
		ft_str_add_back(token, first_char);
		inc_cursor(tok);
	}
	tok->next_token = token;
	return (true);
}

bool	get_next_token(t_tokenizer *tok)
{
	t_string	token;

	if (ft_strchr(OP, cursor_char(tok)))
		return (get_operator_token(tok));
	token = ft_str_new(NULL);
	while (cursor_char(tok))
	{
		if (end_of_token(tok))
			break ;
		if (cursor_char(tok) == '\'')
			eval_quote(tok);
		else if (cursor_char(tok) == '\"')
			eval_dquote(tok);
		ft_str_add_back(token, cursor_char(tok));
		inc_cursor(tok);
	}
	tok->next_token = token;
	if (tok->state == QUOTE)
		print_error("found unclosed quotes");
	else if (tok->state == DQUOTE)
		print_error("found unclosed double quotes");
	return (tok->state == TEXT);
}

t_list	*tokenize(t_tokenizer *tok)
{
	t_list	*lst;

	lst = NULL;
	while (cursor_char(tok))
	{
		while (ft_strchr(WHITESPACE, cursor_char(tok)))
			inc_cursor(tok);
		if (!get_next_token(tok))
		{
			ft_str_free(tok->next_token);
			ft_lstclear(&lst, ft_str_free);
			return (NULL);
		}
		ft_lstadd_back(&lst, ft_lstnew(tok->next_token));
		tok->next_token = NULL;
	}
	return (lst);
}
