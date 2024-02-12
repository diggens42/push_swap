/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:16:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/11 15:41:08 by fwahl            ###   ########.fr       */
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

void	swap_a(t_stack **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	swap_both(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}
