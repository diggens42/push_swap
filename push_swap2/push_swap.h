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
	int		idx;
	int		cost; // cost to push
	bool	best; // cheapest node to push
	struct s_stack_node	*next;
	struct s_stack_node	*prev;
	struct s_stack_node	*target;
}	t_stack_node;

//main

//moves
void	swap_a(t_stack_node **a);
void	swap_b(t_stack_node **b);
void	swap_both(t_stack_node **a, t_stack_node **b);
void	rotate_a(t_stack_node **a);
void	rotate_b(t_stack_node **b);
void	rotate_both(t_stack_node **a, t_stack_node **b);
void	reverse_rotate_a(t_stack_node **a);
void	reverse_rotate_b(t_stack_node **b);
void	reverse_rotate_both(t_stack_node **a, t_stack_node **b);
void	push_a(t_stack_node **a, t_stack_node **b);
void	push_b(t_stack_node **a, t_stack_node **b);


#endif
