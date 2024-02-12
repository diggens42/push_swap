/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:57:29 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 20:03:02 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_3(t_stack **a)
{
	int	top;
	int	mid;
	int	bot;

	top = (*a)->num;
	mid = (*a)->next->num;
	bot = (*a)->next->next->num;
	if (bot > mid && mid < top && top < bot)
		swap_a(a);
	else if (bot < mid && mid > top && top < bot)
	{
		reverse_rotate_a(a);
		swap_a(a);
	}
	else if (bot > mid && mid < top && top > bot)
		rotate_a(a);
	else if (bot < mid && mid > top && top > bot)
		reverse_rotate_a(a);
	else if (bot < mid && mid < top && top > bot)
	{
		rotate_a(a);
		swap_a(a);
	}
}

static void	sort_stacks(t_stack **a, t_stack **b)
{
	int		size;
	t_stack	*best_node;

	size = list_size(*a);
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
}

void	sort_check(t_stack *a, t_stack *b, int argc, bool split)
{
	if (split == true)
		argc++;
	if (argc == 3 && !(is_sorted(a)))
		swap_a(&a);
	if (argc == 4)
		sort_3(&a);
	if (argc > 4)
		sort_stacks(&a, &b);
	free_stacks(a, b);
}
