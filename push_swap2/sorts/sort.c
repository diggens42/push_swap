/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:29 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/04 18:03:31 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

// void	print_list(t_stack *stack)
// {
// 	while (stack)
// 	{
// 		printf("%d\n", stack->num);
// 		stack = stack-> next;
// 	}
// }

void	sort_stacks(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*best_node;

	size = list_len(*a);
	if (size-- > 3 && !(is_sorted(*a)))
		push_b(a, b);
	if (size-- > 3 && !(is_sorted(*a)))
		push_b(a, b);
	while (size-- > 3 && !(is_sorted(*a)))
	{
		init_move_cost(*a, *b);
		best_node = calc_lowest_cost(*a, *b);
		rotate_to_top(a, b, best_node);
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
	print_list(*a);
}
