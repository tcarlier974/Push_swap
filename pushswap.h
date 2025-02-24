/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pushswap.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:17:27 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/24 22:59:16 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSHSWAP_H
# define PUSHSWAP_H

# include <stdlib.h>
# include <unistd.h>
# include "./libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
	int				index;
}	t_stack;

typedef struct s_data
{
	t_stack	*a;
	t_stack	*b;
}	t_data;

typedef struct s_sort
{
	int		max_bits;
	int		size;
	int		i;
	int		j;
}	t_sort;

int		parse_args(int ac, char **av, t_data *data);
void	simple_sort(t_data *data);
void	free_stack(t_stack **stack);
void	swap_a(t_data *data);
void	swap_b(t_data *data);
void	swap_s(t_data *data);
void	push_a(t_data *data);
void	push_b(t_data *data);
void	push_p(t_data *data);
void	rotate_a(t_data *data);
void	rotate_b(t_data *data);
void	rotate_r(t_data *data);
void	reverse_rotate_a(t_data *data);
void	reverse_rotate_b(t_data *data);
void	reverse_rotate_r(t_data *data);
void	sort(t_data *data);
int		is_sorted(t_stack *stack);
int		get_min(t_stack *stack);
int		get_max(t_stack *stack);
int		ft_stacksize(t_stack *stack);
t_stack	*get_next_min(t_stack **stack);
int		parse_arg(char *arg, t_stack **stack);
void	free_args(char **args);
char	**old_args(char **av);
void	four_check(char *str);
long	ft_atol(char *ptr);
int		is_sorted(t_stack *stack);
int		get_min_simple(t_stack *stack, int exclude);

#endif
