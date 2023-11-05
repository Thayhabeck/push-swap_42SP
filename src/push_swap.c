/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:29:35 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/06 14:57:14 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	**args;
	int		size;

	args = NULL;
	stack_a = NULL;
	size = argc;
	if (argc == 1)
		exit(0);
	args = fill_argument(&size, argv);
	stack_a = fill_stacka(stack_a, args);
	check_order(stack_a);
	stack_b = NULL;
	if (size <= 3)
		sort_three_nbr(&stack_a);
	else if (size <= 5)
		sort_five_nbr(&stack_a, &stack_b);
	else
	{
		set_indexes(stack_a);
		big_sort(&stack_a, &stack_b);
	}
	ft_free_array(args);
	stack_free(&stack_a, stack_len(stack_a));
}
