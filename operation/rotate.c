/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:43:08 by tcarlier          #+#    #+#             */
/*   Updated: 2025/01/23 18:22:48 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	rotate_a(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	last = data->a;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "ra\n", 3);
}

void	rotate_b(t_data *data)
{
	t_stack	*tmp;
	t_stack	*last;

	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	last = data->b;
	while (last->next)
		last = last->next;
	last->next = tmp;
	tmp->next = NULL;
	write(1, "rb\n", 3);
}

void	rotate_r(t_data *data)
{
	rotate_a(data);
	rotate_b(data);
}
