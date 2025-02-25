/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 21:15:19 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/26 00:26:27 by tcarlier         ###   ########.fr       */
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

void	freezer(t_stack **a, t_stack **b, char **args, char **av)
{
	if (*a)
		free_stack(a);
	if (*b)
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

void	exit_error(t_stack **a, t_stack **b, char **args, char **av)
{
	freezer(a, b, args, av);
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	init_for_args(char ***args, int *ac, char ***av, int *k)
{
	*args = *av;
	*(ac)--;
	*k = 0;
}
