/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: thabeck- <thabeck-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 00:46:00 by thabeck-          #+#    #+#             */
/*   Updated: 2023/01/24 19:54:02 by thabeck-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"

/******************************************************************************\
 * structs
\******************************************************************************/

typedef struct s_stack
{
	struct s_stack		*next;
	struct s_stack		*prev;
	int					index;
	int					value;
	int					nbr;
	int					sa;
	int					sb;
	int					ra;
	int					rb;
	int					rra;
	int					rrb;
	int					move;
}	t_stack;

typedef struct s_sequence
{
	int	start;
	int	index;
	int	max_index;
	int	length;
	int	max_length;
}	t_sequence;

typedef struct max
{
	int	nb;
	int	size;
}	t_max;

/******************************************************************************\
 * push_swap
\******************************************************************************/

int			main(int argc, char **argv);

/******************************************************************************\
 * arguments
\******************************************************************************/

void		error(char **args, t_stack *stack);
void		check_number(char *str, char **args, t_stack *stack);
int			check_arg(char *str, char **args, t_stack *stack);
char		**fill_argument(int *size, char **argv);

/******************************************************************************\
 * stack_utils
\******************************************************************************/

void		check_order(t_stack *stack);
void		down_node(t_stack *stack, t_stack *node, char **args);
t_stack		*stack_new(int nbr);
t_stack		*fill_stacka(t_stack *stack, char **args);
int			*stack_dup(int *args, t_stack *stack);
int			stack_len(t_stack *stack);
void		stack_free(t_stack **stack, int size);

/******************************************************************************\
 * index_utils
\******************************************************************************/

void		swapidx_init(int max, t_stack **node, int a);
int			partition(t_stack *stack, int *args, int start, int end);
void		quicksort(t_stack *stack, int *args, int start, int end);
void		set_indexes(t_stack *stack);

/******************************************************************************\
 * sort_three_nbr
\******************************************************************************/

int			check_case(t_stack *stack);
void		sort_three_nbr(t_stack **stack);

/******************************************************************************\
 * sort_five_nbr
\******************************************************************************/

int			fivelen_case(t_stack **stack_a, t_stack **stack_b, int size);
int			set_moves_1(t_stack **stack_a, t_stack **stack_b, int size);
void		xtreme_case(t_stack **stack_a, t_stack **stack_b);
void		set_moves_2(t_stack **stack_a, t_stack **stack_b);
void		sort_five_nbr(t_stack **stack_a, t_stack **stack_b);

/******************************************************************************\
 * big_sort
\******************************************************************************/

void		big_sort(t_stack **stack_a, t_stack **stack_b);
t_sequence	*set_sequence(t_stack **stack);
void		fill_sequence(t_stack *n, t_sequence **seq, int i, t_stack **s);
void		set_flag(t_stack **stack_a, t_sequence *seq);
void		init_flag(t_stack **stack_a);

/******************************************************************************\
 * big_sort_utils
\******************************************************************************/

void		check_swapa(t_stack **stack, t_sequence **seq);
void		start_moves(t_stack **stack_a, int n);
void		find_opt(t_stack **stack_a, t_stack **stack_b);
void		stack_consruct(t_stack **stack_a, t_stack **b);
void		push_one(t_stack **stack_a, t_stack **stack_b);
void		set_max(t_max **max, t_stack **stack_a);
int			is_max(t_stack *a, t_stack *b);
int			find_index(t_stack *a, t_stack *b, int max, t_stack *node);
void		loop_find_zone(t_stack **stack_a, t_stack **b, t_max **max);
void		find_zone(t_max **max, int i, t_stack **b, t_stack *a);
void		reorder(t_stack **stack, int size, int index);
void		check_last_index(t_stack **stack, t_stack *node, t_max *max, int j);

/******************************************************************************\
 * moves
\******************************************************************************/

void		move(t_stack **stack_a, t_stack **stack_b, t_stack **node);
void		move_1(t_stack **stack_a, t_stack **stack_b, t_stack **node);
void		move_2(t_stack **stack_a, t_stack **stack_b, t_stack **node);

/******************************************************************************\
 * push
\******************************************************************************/

void		set_nodes(t_stack **l, t_stack **n, t_stack **s, t_stack **b);
void		pa(t_stack **stack_a, t_stack **stack_b);
void		pb(t_stack **stack_a, t_stack **stack_b);

/******************************************************************************\
 * swap
\******************************************************************************/

void		sa(t_stack **stack, int a);
void		sb(t_stack **stack, int a);

/******************************************************************************\
 * rotate
\******************************************************************************/

void		ra(t_stack **stack, int a);
void		rb(t_stack **stack, int a);
void		rr(t_stack **stack_a, t_stack **stack_b);

/******************************************************************************\
 * reverse_rotate
\******************************************************************************/

void		rra(t_stack **stack, int a);
void		rrb(t_stack **stack, int a);
void		rrr(t_stack **stack_a, t_stack **stack_b);

#endif