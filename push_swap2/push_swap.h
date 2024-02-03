#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <stdbool.h>
# include <stdarg.h>
# include <limits.h>
# include "libft/libft.h"

typedef struct s_stack_node
{
	int		num;
	int		move_cost; // cost to move a node to top of the stack
	bool	best; // cheapest node to push
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

//main
int				main(int argc, char **argv);

//sorts
void			sort_3(t_stack_node **a);
void			sort_stacks(t_stack_node **a, t_stack_node **b);

//calcs
void			init_move_cost(t_stack_node *a, t_stack_node *b);
t_stack_node	*calc_lowest_cost(t_stack_node *a, t_stack_node *b);
void			rotate_best_to_top(t_stack_node **a, t_stack_node **b, t_stack_node *best_node);

//moves
void			swap_a(t_stack_node **a);
void			swap_b(t_stack_node **b);
void			swap_both(t_stack_node **a, t_stack_node **b);
void			rotate_a(t_stack_node **a);
void			rotate_b(t_stack_node **b);
void			rotate_both(t_stack_node **a, t_stack_node **b);
void			reverse_rotate_a(t_stack_node **a);
void			reverse_rotate_b(t_stack_node **b);
void			reverse_rotate_both(t_stack_node **a, t_stack_node **b);
void			push_a(t_stack_node **a, t_stack_node **b);
void			push_b(t_stack_node **a, t_stack_node **b);

//errors
void			check_stacks(t_stack_node *a, t_stack_node *b);
void			check_duplicates(t_stack_node *a, t_stack_node *b);
void			check_int_limits(t_stack_node *a, t_stack_node *b);
void			check_argv(char *argv);
void			wrong_input_check(char *argv);
void			check_empty_string(char *argv);

//utils
int				is_sorted(t_stack_node *stack);
int				update_argc(char **argv);
void			free_stack(t_stack_node *stack);
void			free_stacks(t_stack_node *a, t_stack_node *b);
char			**split_argv(char **argv);
int				list_len(t_stack_node *stack);
t_stack_node	*smallest_node(t_stack_node *stack);
t_stack_node	*biggest_node(t_stack_node *stack);
t_stack_node	*closest_biggest_node(t_stack_node *stack, int num);
t_stack_node	*closest_smallest_node(t_stack_node *stack, int num);
void			order_a(t_stack_node **a, t_stack_node *best_node);

#endif
