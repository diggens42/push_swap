/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_checker.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:46:39 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:39:23 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	rotate(t_stack **stack)
{
	t_stack	*first;
	t_stack	*last;

	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	first = *stack;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	*stack = first->next;
	(*stack)->prev = NULL;
	last->next = first;
	first->prev = last;
	first->next = NULL;
}

void	rotate_a_checker(t_stack **a)
{
	rotate(a);
}

void	rotate_b_checker(t_stack **b)
{
	rotate(b);
}

void	rotate_both_checker(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
