/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five_nbr.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 20:20:44 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/06 14:56:59 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	fivelen_case(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size == 5)
	{
		if ((*stack_b)->nbr < (*stack_a)->nbr
			&& (*stack_b)->nbr > (*stack_a)->prev->nbr)
		{
			pa(stack_a, stack_b);
			rra(stack_a, 1);
			rra(stack_a, 1);
			return (1);
		}
	}
	return (0);
}

int	set_moves_1(t_stack **stack_a, t_stack **stack_b, int size)
{
	if ((*stack_b)->nbr > (*stack_a)->prev->nbr)
	{
		pa(stack_a, stack_b);
		ra(stack_a, 1);
	}
	else if ((*stack_b)->nbr < (*stack_a)->nbr)
		pa(stack_a, stack_b);
	else if ((*stack_b)->nbr > (*stack_a)->nbr
		&& (*stack_b)->nbr < (*stack_a)->next->nbr)
	{
		pa(stack_a, stack_b);
		sa(stack_a, 1);
	}
	else if ((*stack_a)->prev->nbr > (*stack_b)->nbr
		&& (*stack_b)->nbr > (*stack_a)->prev->prev->nbr)
	{
		rra(stack_a, 1);
		pa(stack_a, stack_b);
		if (fivelen_case(stack_a, stack_b, size))
			return (0);
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	return (1);
}

void	xtreme_case(t_stack **stack_a, t_stack **stack_b)
{
	ra(stack_a, 1);
	ra(stack_a, 1);
	pa(stack_a, stack_b);
	rra(stack_a, 1);
	rra(stack_a, 1);
}

void	set_moves_2(t_stack **stack_a, t_stack **stack_b)
{
	if ((*stack_b)->nbr < (*stack_a)->nbr)
		pa(stack_a, stack_b);
	else if ((*stack_b)->nbr > (*stack_a)->prev->nbr)
	{
		pa(stack_a, stack_b);
		ra(stack_a, 1);
	}
	else if ((*stack_b)->nbr > (*stack_a)->nbr
		&& (*stack_b)->nbr < (*stack_a)->next->nbr)
	{
		pa(stack_a, stack_b);
		sa(stack_a, 1);
	}
	else if ((*stack_b)->nbr < (*stack_a)->prev->nbr
		&& (*stack_b)->nbr > (*stack_a)->prev->prev->nbr)
	{
		rra(stack_a, 1);
		pa(stack_a, stack_b);
		ra(stack_a, 1);
		ra(stack_a, 1);
	}
	else
		xtreme_case(stack_a, stack_b);
}

void	sort_five_nbr(t_stack **stack_a, t_stack **stack_b)
{
	if (stack_len((*stack_a)) == 4)
	{
		if ((*stack_a)->nbr < (*stack_a)->next->nbr
			&& (*stack_a)->next->nbr < (*stack_a)->next->next->nbr
			&& (*stack_a)->prev->nbr > (*stack_a)->prev->prev->nbr)
			return ;
		pb(stack_a, stack_b);
		sort_three_nbr(stack_a);
		set_moves_1(stack_a, stack_b, 4);
	}
	else
	{
		if (((*stack_a)->nbr < (*stack_a)->next->nbr)
			&& ((*stack_a)->next->nbr < (*stack_a)->next->next->nbr)
			&& ((*stack_a)->next->next->nbr < (*stack_a)->prev->prev->nbr)
			&& ((*stack_a)->prev->prev->nbr < (*stack_a)->prev->nbr))
			return ;
		pb(stack_a, stack_b);
		pb(stack_a, stack_b);
		sort_three_nbr(stack_a);
		if (set_moves_1(stack_a, stack_b, 5))
			set_moves_2(stack_a, stack_b);
	}
}
