/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:29:29 by laube             #+#    #+#             */
/*   Updated: 2021/09/16 21:31:44 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "builtin.h"
#include "parse.h"

int	execution_control(t_node *node)
{
	if (ft_strncmp(node->prg, "echo", 5) == 0)
		ft_echo(node);
	else if (ft_strncmp(node->prg, "pwd", 4) == 0)
		ft_pwd();
	else if (ft_strncmp(node->prg, "cd", 3) == 0)
		ft_cd(node);
	else if (ft_strncmp(node->prg, "env", 4) == 0)
		ft_env();
	else if (ft_strncmp(node->prg, "unset", 6) == 0)
		ft_unset(node);
	else if (ft_strncmp(node->prg, "export", 7) == 0)
		ft_export(node);
	else if (ft_strncmp(node->prg, "exit", 5) == 0)
	{
		ft_exit(node);
		return (1);
	}
	// else
	// 	ft_binary(phrase);
	return (0);
}

int	main_control(t_node *node)
{
	while (node)
	{
		node->prg = interpolate(node->prg);
		interpolate_arr(node->args);
		interpolate_redirs(node->redirs);
		// if (operation_control() == 1)
		// 	return (1);
		execution_control(node);
		node = node->next;
	}
	return (0);
}
