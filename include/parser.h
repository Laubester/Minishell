/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/25 23:11:20 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/14 12:53:24 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PARSER_H
# define PARSER_H

# include "libft.h"
# include "phrase.h"

t_phrase	*parse(t_list *tokens);
char		*parse_spec_char(char *str);
void		parse_special_chars_arr(char **arr);
t_phrase	*get_operator_first_node(t_list **tokens);
bool		appended_redirection(t_phrase **cmds, t_list **tokens);

#endif
