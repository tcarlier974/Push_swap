/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:27:34 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/26 00:16:20 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

static int	is_valid_arg(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '-')
		i++;
	if (i == 1 && !arg[i])
		return (0);
	while (arg[i])
	{
		if (!ft_isdigit(arg[i]))
			return (0);
		i++;
	}
	if (ft_atol(arg) > 2147483647 || ft_atol(arg) < -2147483648)
		return (0);
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

static void	index_stack(t_stack **stack)
{
	t_stack	*head;
	int		index;

	index = 0;
	head = get_next_min(stack);
	while (head)
	{
		head->index = index++;
		head = get_next_min(stack);
	}
}

int	parse_args(int ac, char **av, t_data *data, int k)
{
	int	i;

	if (k == 0)
	{
		i = ac;
		while (i > 0)
		{
			if (!parse_arg(av[i], &data->a))
				return (0);
			i--;
		}
	}
	else
	{
		i = ac - 1;
		while (i >= 0)
		{
			if (!parse_arg(av[i], &data->a))
				return (0);
			i--;
		}
	}
	index_stack(&data->a);
	return (1);
}
