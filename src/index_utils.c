/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   index_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 21:25:50 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/06 14:57:18 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	swapidx_init(int max, t_stack **node, int a)
{
	if (a)
		while ((*node)->index != max)
			*node = (*node)->next;
	else
		while ((*node)->index != max)
			*node = (*node)->prev;
}

int	partition(t_stack *stack, int *args, int start, int end)
{
	int		i;
	int		j;
	t_stack	*fst_node;
	t_stack	*lst_node;

	i = 0;
	j = 0;
	while (end - j > start + i)
	{
		while ((args[start] > args[start + i]))
			i++;
		while ((args[start] < args[end - j]))
			j++;
		if (end - j < start + i)
			break ;
		ft_swap(&args[start + i], &args[end - j]);
		fst_node = stack;
		lst_node = stack->prev;
		swapidx_init(start + i, &fst_node, 1);
		swapidx_init(end - j, &lst_node, 0);
		ft_swap(&fst_node->index, &lst_node->index);
	}
	ft_swap(&args[start], &args[end - j]);
	return (end - j);
}

void	quicksort(t_stack *stack, int *args, int start, int end)
{
	int	head;

	if (start < end)
	{
		head = partition(stack, args, start, end);
		quicksort(stack, args, start, head - 1);
		quicksort(stack, args, head + 1, end);
	}
}

void	set_indexes(t_stack *stack)
{
	int		*args;
	int		i;
	t_stack	*node;

	args = NULL;
	args = stack_dup(args, stack);
	node = stack;
	i = 0;
	while (node->next != stack)
	{
		node->index = i++;
		node = node->next;
	}
	node->index = i;
	quicksort(stack, args, 0, stack_len(stack) - 1);
	node = stack;
	free(args);
}
