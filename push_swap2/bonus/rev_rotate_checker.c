/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rev_rotate_checker.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 15:45:54 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:39:19 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*second_last;

	last = *stack;
	second_last = NULL;
	if (*stack == NULL || (*stack)->next == NULL)
		return ;
	while (last->next != NULL)
	{
		second_last = last;
		last = last->next;
	}
	if (second_last != NULL)
		second_last->next = NULL;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev = NULL;
	*stack = last;
}

void	reverse_rotate_a_checker(t_stack **a)
{
	reverse_rotate(a);
}

void	reverse_rotate_b_checker(t_stack **b)
{
	reverse_rotate(b);
}

void	reverse_rotate_both_checker(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
