/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:37:33 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/06 14:57:49 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	*stack_dup(int *args, t_stack *stack)
{
	int		i;
	t_stack	*node;

	i = 0;
	node = stack;
	args = malloc(sizeof(int) * stack_len(stack));
	while (node->next != stack)
	{
		args[i] = node->nbr;
		node = node->next;
		i++;
	}
	args[i] = node->nbr;
	return (args);
}

int	stack_len(t_stack *stack)
{
	t_stack	*list;
	int		i;

	if (!stack)
		return (0);
	if (stack->next == stack && stack->prev == stack)
		return (1);
	if (stack->next->next == stack || stack->prev == stack)
		return (2);
	list = stack;
	i = 1;
	while (list->next != stack)
	{
		list = list->next;
		i++;
	}
	return (i);
}

void	stack_free(t_stack **stack, int size)
{
	t_stack	*node;
	int		i;

	i = 0;
	node = *stack;
	while (i < size - 1)
	{
		node = node->next;
		free(node->prev);
		i++;
	}
	free(node);
}
