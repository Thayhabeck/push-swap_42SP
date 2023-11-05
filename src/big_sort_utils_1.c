/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_sort_utils_1.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:03:21 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/24 19:52:51 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_swapa(t_stack **stack, t_sequence **seq)
{
	t_sequence	*tmp_seq;

	sa(stack, 0);
	tmp_seq = set_sequence(stack);
	if (tmp_seq->max_length > (*seq)->max_length)
	{
		write(1, "sa\n", 3);
		set_flag(stack, tmp_seq);
		free(*seq);
		*seq = tmp_seq;
	}
	else
	{
		free(tmp_seq);
		sa(stack, 0);
	}
}

void	start_moves(t_stack **stack_a, int n)
{
	t_stack	*node;

	node = *stack_a;
	while (node->next != *stack_a)
	{
		node->sa = n;
		node->sb = n;
		node->ra = n;
		node->rb = n;
		node->rra = n;
		node->rrb = n;
		node->move = n;
		node = node->next;
	}
	node->sa = n;
	node->sb = n;
	node->ra = n;
	node->rb = n;
	node->rra = n;
	node->rrb = n;
	node->move = n;
}

void	find_opt(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		i;
	int		size;

	b = *stack_b;
	i = 0;
	size = stack_len(*stack_b);
	while (b->next != *stack_b)
	{
		if (i <= size / 2)
			b->rb = i;
		else
			b->rrb = size - i;
		stack_consruct(stack_a, &b);
		i++;
		b = b->next;
	}
	if (i <= size / 2)
		b->rb = i;
	else
		b->rrb = size - i;
	stack_consruct(stack_a, &b);
	push_one(stack_a, stack_b);
}

void	stack_consruct(t_stack **stack_a, t_stack **b)
{
	t_max	*max;
	int		i;

	set_max(&max, stack_a);
	i = is_max(*stack_a, (*b));
	if (i <= max->size / 2 && i >= 0)
	{
		(*b)->move = 1;
		(*b)->ra = i + 1;
		free(max);
		return ;
	}
	else if (i > max->size / 2 && i >= 0)
	{
		(*b)->move = 2;
		(*b)->rra = max->size - i - 1;
		free(max);
		return ;
	}
	loop_find_zone(stack_a, b, &max);
	free(max);
}

void	push_one(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*node;
	t_stack	*mem;
	int		max_moves;

	max_moves = 2147483647;
	node = *stack_b;
	while (node->next != *stack_b)
	{
		if (node->sa + node->sb + node->ra + node->rb
			+ node->rra + node->rrb < max_moves)
		{
			max_moves = node->sa + node->sb + node->ra
				+ node->rb + node->rra + node->rrb;
			mem = node;
		}
		node = node->next;
	}
	if (node->sa + node->sb + node->ra + node->rb
		+ node->rra + node->rrb < max_moves)
	{
		max_moves = node->sa + node->sb + node->ra
			+ node->rb + node->rra + node->rrb;
		mem = node;
	}
	move(stack_a, stack_b, &mem);
}
