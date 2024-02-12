/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:59:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 20:00:47 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	update_argc(char **argv)
{
	int	new_argc;

	new_argc = 0;
	while (argv[new_argc] != NULL)
		new_argc++;
	return (new_argc);
}

int	list_size(t_stack *stack)
{
	int		len;
	t_stack	*current;

	current = stack;
	len = 0;
	while (stack)
	{
		len++;
		stack = stack -> next;
	}
	return (len);
}

void	free_stack(t_stack *stack)
{
	t_stack	*current;
	t_stack	*next_node;

	current = stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
	stack = NULL;
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

void	free_split(char **str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return ;
	while (str[i] != NULL)
	{
		free(str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
