/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:15:19 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/25 22:44:03 by tcarlier         ###   ########.fr       */
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

void	freezer(t_stack **a, t_stack **b, char **args)
{
	free_args(args);
	free_stack(a);
	free_stack(b);
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
