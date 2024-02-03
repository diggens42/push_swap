/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:16:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/03 19:15:14 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_check(t_stack_node *a, t_stack_node *b, int argc)
{
	if (argc == 4)
		sort_3(&a);
	if (argc > 4)
		sort_stacks(&a, &b);
}

static void	add_to_stack(t_stack_node **stack, long num)
{
	t_stack_node	*new_node;
	t_stack_node	*current;
	
	new_node = malloc(sizeof(t_stack_node));
	if (new_node == NULL)
		exit(EXIT_FAILURE);
	new_node->num = num;
	new_node->next = NULL;
	new_node->prev = NULL;
	if (*stack == NULL)
		*stack = new_node;
	else
	{
		current = *stack;
		while (current->next != NULL)
			current = current->next;
		current->next = new_node;
		new_node->prev = current;
	}
}

static void	initialize_stack(int argc, char **argv, t_stack_node **a)
{
	int		i;
	long	num;
	
	i = 1;
	while (i < argc)
	{
		check_argv(argv[i]);
		num = ft_atol(argv[i]);
		add_to_stack(a, num);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack_node	*a;
	t_stack_node	*b;
	
	a = NULL;
	b = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		return (1);
	if (argc == 2)
	{
		check_argv(argv[1]);
		argv = split_argv(argv);
		argc = update_argc(argv);
	}
	initialize_stack(argc, argv, &a);
	check_stacks(a, b);
	sort_check(a, b, argc);
	return (0);
}