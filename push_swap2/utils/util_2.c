/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:52:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:54:12 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack *stack)
{
	t_stack	*current;

	if (stack == NULL || stack->next == NULL)
		return (1);
	current = stack;
	while (current->next != NULL)
	{
		if (current->num > current->next->num)
			return (0);
		current = current->next;
	}
	return (1);
}

t_stack	*smallest_node(t_stack *stack)
{
	t_stack	*smallest;

	if (!stack)
		return (NULL);
	smallest = stack;
	while (stack)
	{
		if (stack->num < smallest->num)
			smallest = stack;
		stack = stack->next;
	}
	return (smallest);
}

t_stack	*biggest_node(t_stack *stack)
{
	t_stack	*biggest;

	if (!stack)
		return (NULL);
	biggest = stack;
	while (stack)
	{
		if (stack->num > biggest->num)
			biggest = stack;
		stack = stack->next;
	}
	return (biggest);
}

t_stack	*closest_biggest_node(t_stack *stack, int num)
{
	t_stack	*closest_biggest;
	t_stack	*current_node;
	long	biggest;

	closest_biggest = NULL;
	biggest = LONG_MAX;
	current_node = stack;
	while (current_node)
	{
		if (current_node->num < biggest && current_node->num > num)
		{
			closest_biggest = current_node;
			biggest = current_node->num;
		}
		current_node = current_node->next;
	}
	if (biggest == LONG_MAX)
		closest_biggest = smallest_node(stack);
	return (closest_biggest);
}

t_stack	*closest_smallest_node(t_stack *stack, int num)
{
	t_stack	*closest_smallest;
	t_stack	*current_node;
	long	smallest;

	closest_smallest = NULL;
	smallest = LONG_MIN;
	current_node = stack;
	while (current_node)
	{
		if (current_node->num > smallest && current_node->num < num)
		{
			closest_smallest = current_node;
			smallest = current_node->num;
		}
		current_node = current_node->next;
	}
	if (smallest == LONG_MIN)
		closest_smallest = biggest_node(stack);
	return (closest_smallest);
}
