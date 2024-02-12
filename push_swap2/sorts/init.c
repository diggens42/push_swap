/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 17:58:04 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:44:02 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	add_to_stack(t_stack **stack, long num)
{
	t_stack	*new_node;
	t_stack	*current;

	new_node = ft_calloc(1, sizeof(t_stack));
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

void	init_stack(int argc, char **argv, t_stack **a, bool split)
{
	int		i;
	long	num;

	i = 1;
	if (split == true)
		i = 0;
	while (i < argc)
	{
		wrong_input_check(argv, i, *a, split);
		num = ft_atol(argv[i]);
		check_int_limit(num, argv, *a, split);
		add_to_stack(a, num);
		i++;
	}
	if (split == true)
		free_split(argv);
}
