/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:43:17 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/26 20:54:14 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_duplicates(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;
	t_stack_node	*checker;
	
	current = a;
	while (current != NULL && current->next != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->num == checker->num)
			{
				write(2, "Error\n", 6);
				free_stacks(a, b);
				exit(EXIT_FAILURE);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}

void	check_int_limits(t_stack_node *a, t_stack_node *b)
{
	t_stack_node	*current;

	current = a;
	while (current != NULL)
	{
		if (current->num > INT_MAX || current->num < INT_MIN)
		{
			write(2, "Error\n", 6);
			free_stacks(a, b);
			exit(EXIT_FAILURE);
		}
		current = current->next;
	}
}

void	wrong_input_check(char *argv)
{
	int	i;

	i = 0;
	while(argv[i] != '\0')
	{
		if (ft_issign(argv[i]) && ft_isdigit(argv[i + 1]) 
			&& !(ft_isdigit(argv[i - 1])))
			i += 2;
		else if (ft_isdigit(argv[i]))
			i++;
		else if (argv[i] == ' ' 
			&& (!(ft_isdigit(argv[i - 1])) && ft_isdigit(argv[i + 1])))
			i++;
		else
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_empty_string(char *argv)
{
	int i;

	i = 0;
	
	while (argv[i] == ' ' || argv[i] == '\t')
		i++;
	if (argv[i] == '\0')
	{
		write(2, "Error\n", 6);
		exit(EXIT_FAILURE);
	}
}