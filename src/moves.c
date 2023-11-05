/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/03 13:12:56 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/06 14:57:16 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	move_2(t_stack **stack_a, t_stack **stack_b, t_stack **node)
{
	while ((*node)->rra && (*node)->rrb)
	{
		rrr(stack_a, stack_b);
		(*node)->rra--;
		(*node)->rrb--;
	}
	while ((*node)->rra)
	{
		rra(stack_a, 1);
		(*node)->rra--;
	}
	while ((*node)->rrb)
	{
		rrb(stack_b, 1);
		(*node)->rrb--;
	}
	while ((*node)->rb)
	{
		rb(stack_b, 1);
		(*node)->rb--;
	}
	pa(stack_a, stack_b);
}

void	move_1(t_stack **stack_a, t_stack **stack_b, t_stack **node)
{
	while ((*node)->ra && (*node)->rb)
	{
		rr(stack_a, stack_b);
		(*node)->ra--;
		(*node)->rb--;
	}
	while ((*node)->ra)
	{
		ra(stack_a, 1);
		(*node)->ra--;
	}
	while ((*node)->rb)
	{
		rb(stack_b, 1);
		(*node)->rb--;
	}	
	while ((*node)->rrb)
	{
		rrb(stack_b, 1);
		(*node)->rrb--;
	}
	pa(stack_a, stack_b);
}

void	move(t_stack **stack_a, t_stack **stack_b, t_stack **node)
{
	if ((*node)->move == 1)
		move_1(stack_a, stack_b, node);
	else if ((*node)->move == 2)
		move_2(stack_a, stack_b, node);
}
