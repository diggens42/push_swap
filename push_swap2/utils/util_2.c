/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 16:52:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/03 14:42:21 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	list_len(t_stack_node *stack)
{
	int				len;
	t_stack_node	*current;

	current = stack;
	len = 0;
	while (current != NULL)
	{
		len++;
		current = current->next;
	}
	return (len);
}

t_stack_node	*smallest_node(t_stack_node *stack)
{
	t_stack_node	*smallest;
	
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

t_stack_node	*biggest_node(t_stack_node *stack)
{
	t_stack_node	*biggest;

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

t_stack_node	*closest_biggest_node(t_stack_node *stack, int num)
{
	t_stack_node	*closest_biggest;
	t_stack_node	*current_node;
	long			biggest;

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

t_stack_node	*closest_smallest_node(t_stack_node *stack, int num)
{
	t_stack_node	*closest_smallest;
	t_stack_node	*current_node;
	long			smallest;

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
