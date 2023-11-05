/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_3.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:07:19 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/24 19:46:49 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	reorder(t_stack **stack, int size, int index)
{
	t_stack	*node;
	int		i;
	int		j;

	node = *stack;
	i = 0;
	j = 0;
	while (node->next != *stack)
	{
		if (node->index == index)
		{
			if (i <= size / 2)
				while (j++ < i)
					ra(stack, 1);
			else
				while (j++ < size - i)
					rra(stack, 1);
			return ;
		}
		i++;
		node = node->next;
	}
	check_last_index(stack, node, &((t_max){i, size}), j);
}

void	check_last_index(t_stack **stack, t_stack *node, t_max *max, int j)
{
	if (node->index == 0)
	{
		if (max->nb <= max->size / 2)
			while (j++ < max->nb)
				ra(stack, 1);
		else
			while (j++ < max->size - max->nb)
				rra(stack, 1);
	}
}
