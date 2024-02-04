/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:43:17 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/04 18:00:24 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_duplicates(t_stack *a, t_stack *b)
{
	t_stack	*current;
	t_stack	*checker;

	current = a;
	while (current != NULL && current->next != NULL)
	{
		checker = current->next;
		while (checker != NULL)
		{
			if (current->num == checker->num)
			{
				write(2, "Error Duplicate\n", 16);
				free_stacks(a, b);
				exit(EXIT_FAILURE);
			}
			checker = checker->next;
		}
		current = current->next;
	}
}

void	check_int_limit(long num, t_stack *a)
{
	if (num > INT_MAX || num < INT_MIN)
	{
		write(2, "Error Int Limits\n", 17);
		free_stack(a);
		exit(EXIT_FAILURE);
	}
}

void	wrong_input_check(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] != '\0')
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
			write(2, "Error Input\n", 12);
			exit(EXIT_FAILURE);
		}
	}
}

void	check_empty_string(char *argv)
{
	int	i;

	i = 0;
	while (argv[i] == ' ' || argv[i] == '\t')
		i++;
	if (argv[i] == '\0')
	{
		write(2, "Error empty string\n", 19);
		exit(EXIT_FAILURE);
	}
}

void	check_argv(char *argv)
{
	wrong_input_check(argv);
	check_empty_string(argv);
}
