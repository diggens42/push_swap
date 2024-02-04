/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:16:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/04 17:45:11 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_check(t_stack *a, t_stack *b, int argc)
{
	if (argc == 4)
		sort_3(&a);
	if (argc > 4)
		sort_stacks(&a, &b);
}

static void	add_to_stack(t_stack **stack, long num)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = malloc(sizeof(t_stack));
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

static void	initialize_stack(int argc, char **argv, t_stack **a)
{
	int		i;
	long	num;

	i = 1;
	while (i < argc)
	{
		check_argv(argv[i]);
		num = ft_atol(argv[i]);
		check_int_limit(num, *a);
		add_to_stack(a, num);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (argc == 1 || (!argv[1][0] && argc == 2))
		return (1);
	if (argc == 2)
	{
		argv = split_argv(argv);
		argc = update_argc(argv);
	}
	initialize_stack(argc, argv, &a);
	check_duplicates(a, b);
	sort_check(a, b, argc);
	return (0);
}
