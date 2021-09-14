/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_control.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: laube <louis-philippe.aube@hotmail.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/31 00:29:29 by laube             #+#    #+#             */
/*   Updated: 2021/09/10 19:28:30 by laube            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "execution.h"

void	execution_control(t_phrase *phrase)
{
	if (ft_strnstr(phrase->name, "echo", 5))
		ft_echo(phrase);
	else if (ft_strnstr(phrase->name, "cd", 3))
		ft_cd(phrase);
	else if (ft_strnstr(phrase->name, "pwd", 4))
		ft_pwd(phrase);
	else if (ft_strnstr(phrase->name, "export", 7))
		ft_export(phrase);
	else if (ft_strnstr(phrase->name, "unset", 6))
		ft_unset(phrase);
	else if (ft_strnstr(phrase->name, "env", 4))
		ft_env(phrase);
	else if (ft_strnstr(phrase->name, "exit", 5))
		ft_exit(phrase);
	else
		ft_binary(phrase);
}

int	main_control(t_phrase *phrase)
{
	g_minishell.phrase = phrase;
	while (g_minishell.phrase)
	{
		g_minishell.phrase->name = parse_spec_char(g_minishell.phrase->name);
		parse_special_chars_arr(g_minishell.phrase->args);
		operation_control();
		g_minishell.phrase = g_minishell.phrase->next;
	}
	return (0);
}
