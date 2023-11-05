/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/18 21:52:11 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/24 18:20:34 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	init_flag(t_stack **stack_a)
{
	t_stack	*node;

	node = *stack_a;
	while (node->next != *stack_a)
	{
		node->value = 0;
		node = node->next;
	}
	node->value = 0;
}

void	set_flag(t_stack **stack_a, t_sequence *seq)
{
	t_stack	*node;
	t_stack	*next;
	int		i;

	init_flag(stack_a);
	i = 0;
	node = *stack_a;
	while (i++ < seq->max_index)
		next = node->next;
	node->value = 1;
	i = node->index;
	next = node->next;
	seq->start = node->index;
	while (next->next != *stack_a)
	{
		if (i == next->index - 1)
		{
			next->value = 1;
			i = next->index;
		}
		next = next->next;
	}
	if (i == next->index - 1)
		next->value = 1;
}

void	fill_sequence(t_stack *n, t_sequence **seq, int i, t_stack **s)
{
	t_stack	*node;
	int		prev;

	node = n->next;
	prev = n->index;
	(*seq)->length = 0;
	(*seq)->index = i;
	while (node->next != *s)
	{
		if (prev == node->index - 1)
		{
			(*seq)->length++;
			prev = node->index;
		}
		node = node->next;
	}
	if (prev == node->index - 1)
		(*seq)->length++;
	node = node->next;
	if ((*seq)->length > (*seq)->max_length)
	{
		(*seq)->max_length = (*seq)->length;
		(*seq)->max_index = (*seq)->index;
	}
}

t_sequence	*set_sequence(t_stack **stack)
{
	t_sequence	*seq;
	t_stack		*node;
	int			i;

	seq = malloc(sizeof(t_sequence));
	seq->length = 1;
	seq->max_length = 0;
	node = *stack;
	i = 0;
	while (node->next != *stack)
	{
		fill_sequence(node, &seq, i, stack);
		node = node->next;
		i++;
	}
	return (seq);
}

void	big_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_sequence	*seq;
	int			i;
	int			len;

	seq = set_sequence(stack_a);
	set_flag(stack_a, seq);
	check_swapa(stack_a, &seq);
	free(seq);
	i = 0;
	len = stack_len(*stack_a);
	while (i <= len)
	{
		if (!((*stack_a)->value))
			pb(stack_a, stack_b);
		else
			ra(stack_a, 1);
		i++;
	}
	while (*stack_b)
	{
		start_moves(stack_b, 0);
		find_opt(stack_a, stack_b);
	}
	reorder(stack_a, len, 0);
}
