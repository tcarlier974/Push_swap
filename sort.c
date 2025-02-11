/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:34:04 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/11 14:30:27 by tcarlier         ###   ########.fr       */
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
	t_stack	*head_a;
	int		i;
	int		j;
	int		size;
	int		nb_nb;

	i = 0;
	head_a = data->a;
	size = ft_stacksize(data->a);
	nb_nb = get_nb_nb(&data->a);
	while (i < nb_nb)
	{
		j = 0;
		while (j++ < size)
		{
			head_a = data->a;
			if ((head_a->index >> i & 1) == 1)
				rotate_a(data);
			else
				push_b(data);
		}
		while (ft_stacksize(data->b) != 0)
			push_a(data);
		i++;
	}
}
