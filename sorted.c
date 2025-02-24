/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:40 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/24 22:50:47 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	get_min_simple(t_stack *stack, int exclude)
{
    int	min;
    int	found;

    found = 0;
    while (stack)
    {
        if (stack->index > exclude && (!found || stack->index < min))
        {
            min = stack->index;
            found = 1;
        }
        stack = stack->next;
    }
    return (min);
}

static int	get_distance(t_stack *stack, int value)
{
    int	dist;

    dist = 0;
    while (stack)
    {
        if (stack->index == value)
            break ;
        stack = stack->next;
        dist++;
    }
    return (dist);
}

static void	sort_3_sub(t_stack **phead, int *pmin, int *pnext_min,
	t_data *data)
{
	if ((*phead)->index == *pmin && (*phead)->next->index != *pnext_min)
	{
		rotate_a(data);
		swap_a(data);
		reverse_rotate_a(data);
	}
	else if ((*phead)->index == *pnext_min)
	{
		if ((*phead)->next->index == *pmin)
			swap_a(data);
		else
			reverse_rotate_a(data);
	}
	else
	{
		if ((*phead)->next->index == *pmin)
			rotate_a(data);
		else
		{
			swap_a(data);
			reverse_rotate_a(data);
		}
	}
}

void	sort_3(t_data *data)
{
	t_stack	*head;
	int		min;
	int		next_min;

	head = data->a;
	min = get_min_simple(data->a, -1);
	next_min = get_min_simple(data->a, min);
	if (is_sorted(data->a))
		return ;
	sort_3_sub(&head, &min, &next_min, data);
}

static void	sort_4(t_data *data)
{
	int	distance;

	if (is_sorted(data->a))
		return ;
	distance = get_distance(data->a, get_min_simple(data->a, -1));
	if (distance == 1)
		rotate_a(data);
	else if (distance == 2)
	{
		rotate_a(data);
		rotate_a(data);
	}
	else if (distance == 3)
		reverse_rotate_a(data);
	if (is_sorted(data->a))
		return ;
	push_b(data);
	sort_3(data);
	push_a(data);
}

void	sort_5(t_data *data)
{
	int	distance;

	distance = get_distance(data->a, get_min_simple(data->a, -1));
	if (distance == 1)
		rotate_a(data);
	else if (distance == 2)
	{
		rotate_a(data);
		rotate_a(data);
	}
	else if (distance == 3)
	{
		reverse_rotate_a(data);
		reverse_rotate_a(data);
	}
	else if (distance == 4)
		reverse_rotate_a(data);
	if (is_sorted(data->a))
		return ;
	push_b(data);
	sort_4(data);
	push_a(data);
}
