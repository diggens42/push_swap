/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_checker.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:44:31 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:38:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	push(t_stack **stack1, t_stack **stack2)
{
	t_stack	*top_stack2;

	if (*stack2 == NULL)
		return ;
	top_stack2 = *stack2;
	*stack2 = top_stack2->next;
	if (*stack2 != NULL)
		(*stack2)->prev = NULL;
	top_stack2->next = NULL;
	if (*stack1 != NULL)
		(*stack1)->prev = top_stack2;
	top_stack2->next = *stack1;
	top_stack2->prev = NULL;
	*stack1 = top_stack2;
}

void	push_a_checker(t_stack **a, t_stack **b)
{
	push(a, b);
}

void	push_b_checker(t_stack **a, t_stack **b)
{
	push(b, a);
}
