/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 00:10:24 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/24 15:59:48 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/push_swap.h"

void	error(char **args, t_stack *stack)
{
	if (args)
		ft_free_array(args);
	if (stack)
		stack_free(&stack, stack_len(stack));
	ft_putstr_fd("Error\n", 2);
	exit(1);
}

void	ok(char **args)
{
	if (args)
		ft_free_array(args);
	exit(0);
}

void	check_number(char *str, char **args, t_stack *stack)
{
	long	nbr;

	nbr = ft_atoi(str);
	if ((nbr < -2147483648) || (nbr > 2147483647))
		error(args, stack);
}

int	check_arg(char *str, char **args, t_stack *stack)
{
	int	i;

	if (!(ft_isdigit_sign(str[0], str[1]) || ft_isdigit(str[0])))
		error(args, stack);
	i = 1;
	while (str[i])
	{
		if (!(ft_isdigit(str[i])))
			error(args, stack);
		i++;
	}
	check_number(str, args, stack);
	return (1);
}

char	**fill_argument(int *size, char **argv)
{
	int		i;
	char	**args;

	i = 0;
	if (*size == 2)
	{
		args = ft_split(argv[1], ' ');
		if (!args)
			exit(1);
		if (!args[1] && check_arg(args[0], args, NULL))
			ok(args);
		*size = ft_arrlen(args);
	}
	else
	{
		args = (char **)malloc(sizeof(char *) * (*size));
		while (i < *size - 1)
		{
			args[i] = ft_strdup(argv[i + 1]);
			i++;
		}
		args[i] = NULL;
		(*size)--;
	}
	return (args);
}
