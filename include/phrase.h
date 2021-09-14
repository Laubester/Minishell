/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   phrase.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mleblanc <mleblanc@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/30 18:38:34 by mleblanc          #+#    #+#             */
/*   Updated: 2021/09/14 12:54:53 by mleblanc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHRASE_H
# define PHRASE_H

# include "libft.h"

typedef enum e_operator
{
	PIPE,
	OUTPUT,
	APPEND,
	INPUT,
	READ,
	NONE,
}	t_operator;

t_operator	get_operator(t_string token);

typedef struct s_phrase
{
	char			*name;
	char			**args;
	t_operator		op;
	struct s_phrase	*next;
	struct s_phrase	*prev;
	int				*fd;
	int				output_fd;
	int				intput_fd;
	int				saved_stdout;
	int				saved_stdin;
}	t_phrase;

void		nodeclear(t_phrase **node);
void		nodeadd_back(t_phrase **lst, t_phrase *new);
t_phrase	*nodelast(t_phrase *lst);

#endif
