/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:13 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/25 22:43:18 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

static	char	**ft_realloc(char **args, size_t size)
{
	char	**new;
	int		i;

	new = malloc(size);
	if (!new)
		return (NULL);
	i = 0;
	while (args[i])
	{
		new[i] = args[i];
		i++;
	}
	new[i] = NULL;
	free_args(args);
	return (new);
}

static char	**new_args(char *name, char **av)
{
	char	**args;
	int		i;

	args = malloc(sizeof(char *) * 2);
	if (!args)
		return (NULL);
	args[0] = name;
	args[1] = NULL;
	i = 0;
	while (av[i])
	{
		args = ft_realloc(args, sizeof(char *) * (i + 3));
		if (!args)
			return (NULL);
		args[i + 1] = av[i];
		i++;
	}
	args[i + 1] = NULL;
	free_split(av);
	return (args);
}

static	int	split_len(char **av)
{
	int	i;

	i = 0;
	while (av[i])
		i++;
	return (i);
}

int	main(int ac, char **av)
{
	t_data	data;
	char	**args;

	data.a = NULL;
	data.b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		four_check(av[1]);
		args = new_args(av[0], ft_split(av[1], ' '));
		ac = split_len(args);
	}
	else
		args = old_args(av);
	if (!parse_args(ac, args, &data))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!is_sorted(data.a))
		simple_sort(&data);
	freezer(&data.a, &data.b, args);
	return (0);
}
