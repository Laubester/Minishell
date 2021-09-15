/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 13:33:08 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/14 22:35:12 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "node.h"

typedef struct s_minishell
{
	char		**env;
	int			code;
	int			*fd;
	int			saved_stdin;
	int			saved_stdout;
	t_node		*phrase;
	int			allow_signal;
}	t_minishell;

extern t_minishell	g_minishell;

char	*ft_getenv(char *var);
void	newline(int signal);
void	nothing(int signal);
void	*print_error(const char *msg);
void	*unexpected_token(const char *token);
void	print_cmds(const t_node *cmds);

#endif
