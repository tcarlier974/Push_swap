/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:25:46 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/24 22:37:50 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	four_check(char *str)
{
	if (ft_strlen(str) == 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}

long	ft_atol(char *ptr)
{
	long long	i;
	long long	sign;
	long long	r;

	i = 0;
	sign = 1;
	r = 0;
	while (ptr[i] && ((ptr[i] >= 9 && ptr[i] <= 13) || ptr[i] == ' '))
		i++;
	if (ptr[i] && (ptr[i] == '-' || ptr[i] == '+'))
	{
		if (ptr[i] == '-')
			sign *= -1;
		i++;
	}
	while (ptr[i] && (ptr[i] >= '0' && ptr[i] <= '9'))
	{
		r = r * 10 + ptr[i] - '0';
		i++;
	}
	return ((long)(r * sign));
}
