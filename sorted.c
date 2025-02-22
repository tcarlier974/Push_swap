/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sorted.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcarlier <tcarlier@student.42perpignan.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/23 17:40:40 by tcarlier          #+#    #+#             */
/*   Updated: 2025/02/22 23:16:04 by tcarlier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

/*
 * Retourne le plus petit index présent dans la pile qui soit strictement supérieur à 'exclude'.
 * Si exclude vaut -1, la fonction renvoie le plus petit index global.
 */
static int	get_min_simple(t_stack *stack, int exclude)
{
    int	min;
    int	found;

    found = 0;
    while (stack)
    {
        if (stack->index > exclude && (!found || stack->index < min))
        {
            min = stack->index;
            found = 1;
        }
        stack = stack->next;
    }
    return (min);
}

/*
 * Retourne la distance (le nombre d'opérations depuis le haut de la pile)
 * pour atteindre l'élément dont l'index est 'value'.
 */
static int	get_distance(t_stack *stack, int value)
{
    int	dist;

    dist = 0;
    while (stack)
    {
        if (stack->index == value)
            break ;
        stack = stack->next;
        dist++;
    }
    return (dist);
}

/*
 * Fonction sous-jacente pour trier 3 éléments.
 * La logique est basée sur les indices min et next_min.
 */
static void	sort_3_sub(t_data *data, int min, int next_min)
{
    t_stack	*head;

    head = data->a;
    if (head->index == min && head->next->index != next_min)
    {
        rotate_a(data);
        swap_a(data);
        reverse_rotate_a(data);
    }
    else if (head->index == next_min)
    {
        if (head->next->index == min)
            swap_a(data);
        else
            reverse_rotate_a(data);
    }
    else
    {
        if (head->next->index == min)
            rotate_a(data);
        else
        {
            swap_a(data);
            reverse_rotate_a(data);
        }
    }
}

/*
 * Trie une pile de 3 éléments en se basant sur leurs indices.
 */
void	sort_three(t_data *data)
{
    int	min;
    int	next_min;

    if (is_sorted(data->a))
        return ;
    min = get_min_simple(data->a, -1);
    next_min = get_min_simple(data->a, min);
    sort_3_sub(data, min, next_min);
}

/*
 * Trie une pile de 4 éléments.
 * Retrouve l'élément minimal selon la distance par rapport au sommet,
 * l'amène en tête, le repousse sur la pile B, trie les 3 restants et le réintègre.
 */
static void	sort_4(t_data *data)
{
    int	distance;
    int	min;

    if (is_sorted(data->a))
        return ;
    min = get_min_simple(data->a, -1);
    distance = get_distance(data->a, min);
    if (distance == 1)
        rotate_a(data);
    else if (distance == 2)
    {
        rotate_a(data);
        rotate_a(data);
    }
    else if (distance == 3)
        reverse_rotate_a(data);
    if (is_sorted(data->a))
        return ;
    push_b(data);
    sort_three(data);
    push_a(data);
}

/*
 * Trie une pile de 5 éléments.
 * Calcule la distance du plus petit élément, effectue les rotations nécessaires,
 * repousse le minimum sur B, trie les 4 éléments restants, puis le réintègre.
 */
void	sort_five(t_data *data)
{
    int	distance;
    int	min;

    min = get_min_simple(data->a, -1);
    distance = get_distance(data->a, min);
    if (distance == 1)
        rotate_a(data);
    else if (distance == 2)
    {
        rotate_a(data);
        rotate_a(data);
    }
    else if (distance == 3)
    {
        reverse_rotate_a(data);
        reverse_rotate_a(data);
    }
    else if (distance == 4)
        reverse_rotate_a(data);
    if (is_sorted(data->a))
        return ;
    push_b(data);
    sort_4(data);
    push_a(data);
}

/*
 * Fonction de tri simple.
 * Elle détermine la taille de la pile et sélectionne l'algorithme adapté.
 */
void	simple_sort(t_data *data)
{
    int	size;

    if (is_sorted(data->a) || ft_stacksize(data->a) <= 1)
        return ;
    size = ft_stacksize(data->a);
    if (size == 2)
        swap_a(data);
    else if (size == 3)
        sort_three(data);
    else if (size == 4)
        sort_4(data);
    else if (size == 5)
        sort_five(data);
}

int	is_sorted(t_stack *stack)
{
	while (stack && stack->next)
	{
		if (stack->value > stack->next->value)
			return (0);
		stack = stack->next;
	}
	return (1);
}
