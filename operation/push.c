/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:43:27 by tcarlier          #+#    #+#             */
/*   Updated: 2025/01/23 18:21:49 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	push_a(t_data *data)
{
	t_stack	*tmp;

	if (!data->b)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = data->a;
	data->a = tmp;
	write(1, "pa\n", 3);
}

void	push_b(t_data *data)
{
	t_stack	*tmp;

	if (!data->a)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = data->b;
	data->b = tmp;
	write(1, "pb\n", 3);
}

void	push_p(t_data *data)
{
	push_a(data);
	push_b(data);
}
