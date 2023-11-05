/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_2.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:05:37 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/24 19:37:54 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	set_max(t_max **max, t_stack **stack_a)
{
	*max = malloc(sizeof(t_max));
	(*max)->nb = 2147483647;
	(*max)->size = stack_len(*stack_a);
}

int	is_max(t_stack *a, t_stack *b)
{
	t_stack	*node;
	int		max;

	node = a;
	while (node->next != a)
	{
		if (node->nbr > b->nbr)
			return (-1);
		node = node->next;
	}
	if (node->nbr > b->nbr)
		return (-1);
	node = a;
	max = -2147483648;
	return (find_index(a, b, max, node));
}

int	find_index(t_stack *a, t_stack *b, int max, t_stack *node)
{
	int		index;
	int		i;

	i = 0;
	while (node->next != a)
	{
		if (b->nbr > node->nbr)
		{
			if (node->nbr > max)
			{
				max = node->nbr;
				index = i;
			}
		}
		node = node->next;
		i++;
	}
	if (b->nbr > node->nbr)
		if (node->nbr > max)
			index = i;
	return (index);
}

void	loop_find_zone(t_stack **stack_a, t_stack **b, t_max **max)
{
	t_stack	*a;
	int		i;

	a = *stack_a;
	i = 0;
	while (a->next != *stack_a)
	{
		find_zone(max, i, b, a);
		a = a->next;
		i++;
	}
	find_zone(max, i, b, a);
}

void	find_zone(t_max **max, int i, t_stack **b, t_stack *a)
{
	int	curr_max;

	if ((*b)->nbr < a->nbr)
	{
		curr_max = a->index - (*b)->index;
		if (curr_max < (*max)->nb)
		{
			(*max)->nb = curr_max;
			if (i <= (*max)->size / 2)
			{
				(*b)->move = 1;
				(*b)->ra = i;
			}
			else
			{
				(*b)->move = 2;
				(*b)->rra = (*max)->size - i;
			}
		}
	}
}
