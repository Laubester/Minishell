/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/18 15:16:25 by mleblanc          #+#    #+#             */
/*   Updated: 2021/08/28 18:32:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "operator.h"
# include <stdbool.h>

# define SHELL_PROMPT "minishell: "

typedef struct s_cmd
{
	char	*name;
	char	**args;
}	t_cmd;

typedef struct s_node
{
	t_cmd		*cmd1;
	t_cmd		*cmd2;
	t_operator	op;
}	t_node;

void	print_error(const char *msg);
void	unexpected_token(const t_string token);
void	free_node(void *node);
void	free_cmd(void *cmd);

#endif
