/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_maker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/04 17:49:11 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/11 16:33:12 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate_optimized(t_stack **a, t_stack **b, t_stack *best_node)
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
}

static void	rev_rotate_optimized(t_stack **a, t_stack **b, t_stack *best_node)
{
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

void	rotate_to_top(t_stack **a, t_stack **b, t_stack *best_node)
{
	while (*a != best_node || *b != best_node->target)
	{
		if (best_node->move_cost > 0 || best_node->target->move_cost > 0)
			rotate_optimized(a, b, best_node);
		if (best_node->move_cost < 0 || best_node->target->move_cost < 0)
			rev_rotate_optimized(a, b, best_node);
	}
}

void	order_a(t_stack **a, t_stack *best_node)
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
