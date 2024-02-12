/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:47:18 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:39:27 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	second = first->next;
	first->next = second->next;
	second->prev = first->prev;
	if (second->next != NULL)
		second->next->prev = first;
	first->prev = second;
	second->next = first;
	*stack = second;
}

void	swap_a_checker(t_stack **a)
{
	swap(a);
}

void	swap_b_checker(t_stack **b)
{
	swap(b);
}

void	swap_both_checker(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
