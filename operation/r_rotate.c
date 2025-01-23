/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   r_rotate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:43:49 by tcarlier          #+#    #+#             */
/*   Updated: 2025/01/23 18:22:17 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	reverse_rotate_a(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!data->a || !data->a->next)
		return ;
	last = data->a;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = data->a;
	data->a = tmp;
	write(1, "rra\n", 4);
}

void	reverse_rotate_b(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!data->b || !data->b->next)
		return ;
	last = data->b;
	while (last->next->next)
		last = last->next;
	tmp = last->next;
	last->next = NULL;
	tmp->next = data->b;
	data->b = tmp;
	write(1, "rrb\n", 4);
}

void	reverse_rotate_r(t_data *data)
{
	reverse_rotate_a(data);
	reverse_rotate_b(data);
}
