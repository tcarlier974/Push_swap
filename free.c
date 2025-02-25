/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:15:19 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/25 23:06:42 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	free_args(char **args)
{
	int	i;

	i = 0;
	while (args[i])
	{
		free(args[i]);
		i++;
	}
	free(args);
}

char	**old_args(char **av)
{
	int		i;
	char	**args;

	i = 0;
	while (av[i])
		i++;
	args = (char **)malloc(sizeof(char *) * (i + 1));
	if (!args)
		return (NULL);
	args = av;
	return (args);
}

void	freezer(t_stack **a, t_stack **b, char **args, char **av)
{
	free_stack(a);
	free_stack(b);
	if (!av[2])
		free_args(args);
}

void	free_split(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}
