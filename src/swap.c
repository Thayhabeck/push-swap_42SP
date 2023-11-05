/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 03:10:48 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/10 21:44:48 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	sa(t_stack **stack, int a)
{
	t_stack	*node;
	int		tmp;

	node = *stack;
	tmp = node->nbr;
	node->nbr = node->next->nbr;
	node->next->nbr = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack, int a)
{
	t_stack	*node;
	int		tmp;

	node = *stack;
	tmp = node->nbr;
	node->nbr = node->next->nbr;
	node->next->nbr = tmp;
	tmp = node->index;
	node->index = node->next->index;
	node->next->index = tmp;
	if (a)
		write(1, "sb\n", 3);
}
