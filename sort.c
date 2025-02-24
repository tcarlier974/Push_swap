/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:34:04 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/24 23:00:01 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

int	get_nb_nb(t_stack **a)
{
	t_stack	*head;
	int		max;
	int		max_nb;

	head = *a;
	max = head->index;
	max_nb = 0;
	while (head)
	{
		if (head->index > max)
			max = head->index;
		head = head->next;
	}
	while ((max >> max_nb) != 0)
		max_nb++;
	return (max_nb);
}

void	sort(t_data *data)
{
	t_sort	sort;
	t_stack	*current;

	sort.size = ft_stacksize(data->a);
	sort.max_bits = 0;
	while (((sort.size - 1) >> sort.max_bits) != 0)
		sort.max_bits++;
	sort.i = 0;
	while (sort.i < sort.max_bits)
	{
		sort.j = 0;
		while (sort.j < sort.size)
		{
			current = data->a;
			if (((current->index >> sort.i) & 1) == 1)
				rotate_a(data);
			else
				push_b(data);
			sort.j++;
		}
		while (ft_stacksize(data->b) != 0)
			push_a(data);
		sort.i++;
	}
}
