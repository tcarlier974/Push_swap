/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:40 by tcarlier          #+#    #+#             */
/*   Updated: 2025/01/23 20:32:48 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

void	sort_three(t_data *data)
{
	if (data->a->value > data->a->next->value)
		swap_a(data);
	if (data->a->value > data->a->next->next->value)
		reverse_rotate_a(data);
	if (data->a->next->value > data->a->next->next->value)
	{
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
}

void	sort_five(t_data *data)
{
	int	min;
	int	max;

	min = get_min(data->a);
	max = get_max(data->a);
	while (ft_stacksize(data->a) > 3)
	{
		if (data->a->value == min || data->a->value == max)
			push_b(data);
		else
			rotate_a(data);
	}
	sort_three(data);
	while (data->b)
	{
		if (data->b->value == min)
			push_a(data);
		else
		{
			rotate_b(data);
			push_a(data);
		}
	}
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
