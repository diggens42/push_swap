/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:59:08 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/29 16:06:25 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	is_sorted(t_stack_node *stack)
{
	t_stack_node *current;

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

int	update_argc(char **argv)
{
	int new_argc;

	new_argc = 0;
	while (argv[new_argc] != NULL)
		new_argc++;
	return (new_argc);
}

void	free_stack(t_stack_node *stack)
{
	t_stack_node	*current;
	t_stack_node	*next_node;
	
	current = stack;
	while (current != NULL)
	{
		next_node = current->next;
		free(current);
		current = next_node;
	}
}

void	free_stacks(t_stack_node *a, t_stack_node *b)
{
	free_stack(a);
	free_stack(b);
}

char	**split_argv(char **argv)
{
	char	**split_argv;
	char	**new_argv;
	int		split_argc;
	int		i;

	split_argv = ft_split(argv[1], ' ');
	split_argc = 0;
	while (split_argv[split_argc] != NULL)
		split_argc++;
	new_argv = malloc((split_argc + 2) * sizeof(char *));
	if (!new_argv)
		return (NULL);
	new_argv[0] = argv[0];
	i = 0;
	while (i < split_argc)
	{
		new_argv[i + 1] = split_argv[i];
		i++;	
	}
	new_argv[split_argc + 1] = NULL;
	free(split_argv);
	return (new_argv);
}