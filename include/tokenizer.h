/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:15:12 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/14 22:32:41 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "libft.h"

# define OP ">|<"

typedef enum e_type
{
	PIPE,
	OUTPUT,
	APPEND,
	INPUT,
	HEREDOC,
	STRING,
}	t_type;

t_type	get_type(t_string token);
bool	is_redirection(t_type type);
char	*type_str(t_type type);

typedef enum e_state
{
	TEXT,
	QUOTE,
	DQUOTE,
}	t_state;

typedef struct s_tokenizer
{
	char			*str;
	unsigned int	cursor;
	t_state			state;
	t_string		next_token;
}	t_tokenizer;

t_list	*tokenize(t_tokenizer *tok);
char	cursor_char(const t_tokenizer *tok);
void	inc_cursor(t_tokenizer *tok);
void	eval_quote(t_tokenizer *tok);
void	eval_dquote(t_tokenizer *tok);
bool	end_of_token(const t_tokenizer *tok);
void	init_tokenizer(t_tokenizer *tok);

#endif
