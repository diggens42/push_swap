/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:55:49 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 20:01:04 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"
# include <stdio.h>

typedef struct s_stack
{
	int				num;
	int				move_cost;
	struct s_stack	*next;
	struct s_stack	*prev;
	struct s_stack	*target;
}	t_stack;

//inits
void			init_stack(int argc, char **argv, t_stack **a, bool split);
void			sort_check(t_stack *a, t_stack *b, int argc, bool split);

//calcs && move maker
void			calc_move_cost(t_stack *stack);
void			init_move_cost(t_stack *a, t_stack *b);
t_stack			*calc_lowest_cost(t_stack *a, t_stack *b);
void			rotate_to_top(t_stack **a, t_stack **b, t_stack *best_node);
void			order_a(t_stack **a, t_stack *best_node);

//moves
void			swap_a(t_stack **a);
void			swap_b(t_stack **b);
void			swap_both(t_stack **a, t_stack **b);
void			rotate_a(t_stack **a);
void			rotate_b(t_stack **b);
void			rotate_both(t_stack **a, t_stack **b);
void			reverse_rotate_a(t_stack **a);
void			reverse_rotate_b(t_stack **b);
void			reverse_rotate_both(t_stack **a, t_stack **b);
void			push_a(t_stack **a, t_stack **b);
void			push_b(t_stack **a, t_stack **b);

//errors
void			check_int_limit(long num, char **argv, t_stack *a, bool split);
void			check_duplicates(char **argv, t_stack *a, bool split);
void			wrong_input_check(char **argv, int i, t_stack *a, bool split);
void			check_empty_string(char **argv);
void			error_check_free(t_stack **a, char **argv, bool split);

//utils
int				is_sorted(t_stack *stack);
int				list_size(t_stack *stack);
int				update_argc(char **argv);
void			free_stack(t_stack *stack);
void			free_stacks(t_stack *a, t_stack *b);
void			free_split(char **str);
t_stack			*smallest_node(t_stack *stack);
t_stack			*biggest_node(t_stack *stack);
t_stack			*closest_biggest_node(t_stack *stack, int num);
t_stack			*closest_smallest_node(t_stack *stack, int num);

//checker(bonus)
void			push_a_checker(t_stack **a, t_stack **b);
void			push_b_checker(t_stack **a, t_stack **b);
void			reverse_rotate_a_checker(t_stack **a);
void			reverse_rotate_b_checker(t_stack **b);
void			reverse_rotate_both_checker(t_stack **a, t_stack **b);
void			rotate_a_checker(t_stack **a);
void			rotate_b_checker(t_stack **b);
void			rotate_both_checker(t_stack **a, t_stack **b);
void			swap_a_checker(t_stack **a);
void			swap_b_checker(t_stack **b);
void			swap_both_checker(t_stack **a, t_stack **b);

#endif
