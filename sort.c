/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:34:04 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/24 22:55:25 by tcarlier         ###   ########.fr       */
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
	int		max_bits;
	int		size;
	int		i;
	int		j;
	t_stack	*current;

	size = ft_stacksize(data->a);
	max_bits = 0;
	while (((size - 1) >> max_bits) != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			current = data->a;
			if (((current->index >> i) & 1) == 1)
				rotate_a(data);
			else
				push_b(data);
			j++;
		}
		while (ft_stacksize(data->b) != 0)
			push_a(data);
		i++;
	}
}
