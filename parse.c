/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:27:34 by tcarlier          #+#    #+#             */
/*   Updated: 2025/01/23 20:42:50 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	is_duplicate(t_stack *stack, int value)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp)
	{
		if (tmp->value == value)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

int	parse_arg(char *arg, t_stack **stack)
{
	t_stack	*new;

	if (!is_valid_arg(arg))
		return (0);
	if (is_duplicate(*stack, ft_atoi(arg)))
		return (0);
	new = malloc(sizeof(t_stack));
	if (!new)
		return (0);
	new->value = ft_atoi(arg);
	new->next = *stack;
	new->index = -1;
	*stack = new;
	return (1);
}

static void	ps_index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = ps_get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = ps_get_next_min(stack);
	}
}

int	parse_args(int ac, char **av, t_data *data)
{
	int	i;

	i = ac - 1;
	while (i > 0)
	{
		if (!parse_arg(av[i], &data->a))
			return (0);
		i--;
	}
	ps_index_stack(&data->a);
	return (1);
}
