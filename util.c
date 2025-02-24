/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/24 22:25:46 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/24 22:49:10 by tcarlier         ###   ########.fr       */
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

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}

void	simple_sort(t_data *data)
{
    int	size;

    if (is_sorted(data->a) || ft_stacksize(data->a) <= 1)
        return ;
    size = ft_stacksize(data->a);
    if (size == 2)
        swap_a(data);
    else if (size == 3)
        sort_3(data);
    else if (size == 4)
        sort_4(data);
    else if (size == 5)
        sort_5(data);
	else
		sort(data);
}
