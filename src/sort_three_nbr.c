/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:51:15 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/06 14:57:39 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	check_case(t_stack *stack)
{
	if ((stack->nbr < stack->next->nbr)
		&& (stack->next->nbr < stack->prev->nbr))
		return (1);
	else if ((stack->nbr > stack->next->nbr)
		&& (stack->next->nbr < stack->prev->nbr)
		&& (stack->prev->nbr > stack->nbr))
		return (2);
	else if ((stack->nbr > stack->next->nbr)
		&& (stack->next->nbr > stack->prev->nbr)
		&& (stack->prev->nbr < stack->nbr))
		return (3);
	else if ((stack->nbr > stack->next->nbr)
		&& (stack->next->nbr < stack->prev->nbr)
		&& (stack->prev->nbr < stack->nbr))
		return (4);
	else if ((stack->nbr < stack->next->nbr)
		&& (stack->next->nbr > stack->prev->nbr)
		&& (stack->prev->nbr > stack->nbr))
		return (5);
	else
		return (6);
}

void	sort_three_nbr(t_stack **stack)
{
	if (stack_len(*stack) == 2 && (*stack)->nbr > (*stack)->next->nbr)
	{
		sa(stack, 1);
		return ;
	}
	if (check_case(*stack) == 1)
		return ;
	else if (check_case(*stack) == 2)
		sa(stack, 1);
	else if (check_case(*stack) == 3)
	{
		ra(stack, 1);
		sa(stack, 1);
	}	
	else if (check_case(*stack) == 4)
		ra(stack, 1);
	else if (check_case(*stack) == 5)
	{
		sa(stack, 1);
		ra(stack, 1);
	}
	else
		rra(stack, 1);
}
