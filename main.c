/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:26:13 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/26 00:12:02 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"
#include <stdio.h>

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
	int		k;

	data.a = NULL;
	data.b = NULL;
	if (ac < 2)
		return (0);
	else if (ac == 2)
	{
		four_check(av[1]);
		args = ft_split(av[1], ' ');
		ac = split_len(args);
		k = 1;
	}
	else
	{
		args = av;
		ac--;
		k = 0;
	}
	if (!parse_args(ac, args, &data, k))
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	if (!is_sorted(data.a))
		simple_sort(&data);
	freezer(&data.a, &data.b, args, av);
	return (0);
}
