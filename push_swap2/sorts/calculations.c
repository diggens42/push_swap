/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:21:30 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/03 19:13:40 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	calc_move_cost(t_stack_node *stack)
{
	int	idx;
	int	size;

	size = list_len(stack);
	idx = 0;
	while (idx < size)
	{
		if (idx <= size / 2)
			stack->move_cost = idx;
		else
			stack->move_cost = idx - size;
		stack = stack->next;
		idx++;	
	}
}

void	init_move_cost(t_stack_node *a, t_stack_node *b)
{
	calc_move_cost(a);
	calc_move_cost(b);
}
int		get_moves_curr(t_stack_node *a, t_stack_node *target)
{
	int	moves_curr;

	if (a->move_cost <= 0 && target->move_cost <= 0)
	{
		if (-a->move_cost < -target->move_cost)
			moves_curr = -target->move_cost;
		else
			moves_curr = -a->move_cost;
	}
	else if (a->move_cost >= 0 && target->move_cost >= 0)
	{
		if (a->move_cost < target->move_cost)
			moves_curr = target->move_cost;
		else
			moves_curr = a->move_cost;
	}
	else
	{
		if (a->move_cost < 0)
			moves_curr = -a->move_cost + target->move_cost;
		else
			moves_curr = a->move_cost + -target->move_cost;
	}
	return (moves_curr);
}

t_stack_node	*calc_lowest_cost(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*lowest_cost;
	int				moves_req;
	int				moves_curr;
	
	moves_req = INT_MAX;
	moves_curr = 0;
	while (a)
	{
		a->target = closest_smallest_node(b, a->num);
		moves_curr = get_moves_curr(a, a->target);
		if (moves_req > moves_curr)
		{
			lowest_cost = a;
			moves_req = moves_curr;
		}
		a = a->next;
	}
	return (lowest_cost);
}

void	rotate_best_to_top(t_stack_node **a, t_stack_node **b, t_stack_node *best_node)
{
	while (*a != best_node || *b != best_node->target)
	{
		if (best_node->move_cost > 0 && best_node->target->move_cost > 0)
		{
			best_node->move_cost--;
			best_node->target->move_cost--;
			rotate_both(a, b);
		}
		else if (best_node->move_cost > 0)
		{
			best_node->move_cost--;
			rotate_a(a);
		}
		else if (best_node->target->move_cost > 0)
		{
			best_node->target->move_cost--;
			rotate_b(b);
		}
		if (best_node->move_cost < 0 && best_node->target->move_cost < 0)
		{
			best_node->move_cost++;
			best_node->target->move_cost++;
			reverse_rotate_both(a, b);
		}
		else if (best_node->move_cost < 0)
		{
			best_node->move_cost++;
			reverse_rotate_a(a);
		}
		else if (best_node->target->move_cost < 0)
		{
			best_node->target->move_cost++;
			reverse_rotate_b(b);
		}
	}
}
void	order_a(t_stack_node **a, t_stack_node *best_node)
{
	calc_move_cost(*a);
	while (*a != best_node)
	{
		if (best_node->move_cost > 0)
			rotate_a(a);
		else
			reverse_rotate_a(a);
	}
}