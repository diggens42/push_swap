/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 14:12:27 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/29 14:14:48 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_3(t_stack_node **a)
{
	long top;
	long mid;
	long bot;
	
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