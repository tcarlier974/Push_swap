/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:39:51 by tcarlier          #+#    #+#             */
/*   Updated: 2025/01/23 18:22:59 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../pushswap.h"

void	swap_a(t_data *data)
{
	t_stack	*tmp;

	if (!data->a || !data->a->next)
		return ;
	tmp = data->a;
	data->a = data->a->next;
	tmp->next = data->a->next;
	data->a->next = tmp;
	write(1, "sa\n", 3);
}

void	swap_b(t_data *data)
{
	t_stack	*tmp;

	if (!data->b || !data->b->next)
		return ;
	tmp = data->b;
	data->b = data->b->next;
	tmp->next = data->b->next;
	data->b->next = tmp;
	write(1, "sb\n", 3);
}

void	swap_s(t_data *data)
{
	swap_a(data);
	swap_b(data);
}
