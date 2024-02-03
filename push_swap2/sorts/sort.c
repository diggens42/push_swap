/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:29 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/03 18:58:06 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_stacks(t_stack_node **a, t_stack_node **b)
{
	int				size;
	t_stack_node	*best_node;

	size = list_len(*a);
	if (size-- > 3 && !(is_sorted(*a)))
		push_b(a, b);
	if (size-- > 3 && !(is_sorted(*a)))
		push_b(a, b);
	while(size-- > 3 && !(is_sorted(*a)))
	{
		init_move_cost(*a, *b);
		best_node = calc_lowest_cost(*a, *b);
		rotate_best_to_top(a, b, best_node);
		push_b(a, b);
	}
	sort_3(a);
	while (*b != NULL)
	{
		best_node = closest_biggest_node(*a, (*b)->num);
		order_a(a, best_node);
		push_a(a, b);
	}
	best_node = smallest_node(*a);
	order_a(a, best_node);
}
