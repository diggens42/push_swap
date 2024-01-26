/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 18:16:47 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/26 20:09:46 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	swap(t_stack_node **stack)
{
	t_stack_node	*first;
	t_stack_node	*second;

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

void	swap_a(t_stack_node **a)
{
	swap(a);
	ft_putstr("sa\n");
}

void	swap_b(t_stack_node **b)
{
	swap(b);
	ft_putstr("sb\n");
}

void	swap_both(t_stack_node **a, t_stack_node **b)
{
	swap(a);
	swap(b);
	ft_putstr("ss\n");
}