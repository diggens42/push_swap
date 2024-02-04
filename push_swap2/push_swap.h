/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:55:49 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/04 17:57:18 by fwahl            ###   ########.fr       */
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

//main
int				main(int argc, char **argv);

//sorts
void			sort_3(t_stack **a);
void			sort_stacks(t_stack **a, t_stack **b);

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
void			check_int_limit(long num, t_stack *a);
void			check_duplicates(t_stack *a, t_stack *b);
void			check_argv(char *argv);
void			wrong_input_check(char *argv);
void			check_empty_string(char *argv);

//utils
int				is_sorted(t_stack *stack);
int				update_argc(char **argv);
void			free_stack(t_stack *stack);
void			free_stacks(t_stack *a, t_stack *b);
char			**split_argv(char **argv);
int				list_len(t_stack *stack);
t_stack			*smallest_node(t_stack *stack);
t_stack			*biggest_node(t_stack *stack);
t_stack			*closest_biggest_node(t_stack *stack, int num);
t_stack			*closest_smallest_node(t_stack *stack, int num);

#endif
