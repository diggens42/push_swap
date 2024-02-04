/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_cost.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 19:21:30 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/04 18:06:21 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	calc_move_cost(t_stack *stack)
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

void	init_move_cost(t_stack *a, t_stack *b)
{
	calc_move_cost(a);
	calc_move_cost(b);
}

static int	get_moves_curr(t_stack *a, t_stack *target)
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

t_stack	*calc_lowest_cost(t_stack *a, t_stack *b)
{
	t_stack	*lowest_cost;
	int		moves_req;
	int		moves_curr;

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
