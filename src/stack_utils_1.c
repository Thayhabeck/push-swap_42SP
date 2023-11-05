/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils_1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 19:27:32 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/25 03:42:11 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	check_order(t_stack *stack)
{
	t_stack	*node;

	node = stack;
	while (node->next != stack)
	{
		if (node->nbr > node->next->nbr)
			return ;
		node = node->next;
	}
	exit(0);
}

void	down_node(t_stack *stack, t_stack *node, char **args)
{
	t_stack	*head;

	head = stack;
	while (head->next != stack)
	{
		if (head->nbr == node->nbr)
			error(args, NULL);
		head = head->next;
	}
	if (head->nbr == node->nbr)
		error(args, NULL);
	if (stack->next == stack && stack->prev == stack)
	{
		stack->next = node;
		stack->prev = node;
		node->prev = stack;
		node->next = stack;
		return ;
	}
	head = stack;
	node->prev = head->prev;
	head->prev->next = node;
	head->prev = node;
	node->next = head;
}

t_stack	*stack_new(int nbr)
{
	t_stack	*stack;

	stack = malloc(sizeof(t_stack));
	stack->nbr = nbr;
	stack->ra = 0;
	stack->rb = 0;
	stack->rra = 0;
	stack->rrb = 0;
	return (stack);
}

t_stack	*fill_stacka(t_stack *stack, char **args)
{
	int		i;

	stack = stack_new(ft_atoi(args[0]));
	stack->next = stack;
	stack->prev = stack;
	i = 1;
	while (args[i])
	{
		if (check_arg(args[i], args, stack))
			down_node(stack, stack_new(ft_atoi(args[i])), args);
		i++;
	}
	return (stack);
}
