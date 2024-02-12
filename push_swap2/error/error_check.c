/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:43:17 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:59:13 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	check_duplicates(char **argv, t_stack *a, bool split)
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
				error_check_free(&a, argv, split);
			checker = checker->next;
		}
		current = current->next;
	}
}

void	check_int_limit(long num, char **argv, t_stack *a, bool split)
{
	if (num > INT_MAX || num < INT_MIN)
		error_check_free(&a, argv, split);
}

void	wrong_input_check(char **argv, int i, t_stack *a, bool split)
{
	int		j;
	bool	has_digit;

	has_digit = false;
	j = 0;
	while (argv[i][j] != '\0')
	{
		if (j == 0 && ft_issign(argv[i][j]) && ft_isdigit(argv[i][j + 1]))
			j++;
		else if (ft_isdigit(argv[i][j]))
		{
			has_digit = true;
			j++;
		}
		else
			error_check_free(&a, argv, split);
	}
	if (has_digit == false)
		error_check_free(&a, argv, split);
}

void	check_empty_string(char **argv)
{
	int	i;
	int	j;

	i = 0;
	while (argv[i] != NULL)
	{
		j = 0;
		while (argv[i][j] == ' ' || argv[i][j] == '\t')
			j++;
		if (argv[i][j] == '\0')
		{
			write(2, "Error\n", 6);
			exit(EXIT_FAILURE);
		}
		i++;
	}
}

void	error_check_free(t_stack **a, char **argv, bool split)
{
	write(2, "Error\n", 6);
	free_stack(*a);
	if (split == true)
		free_split(argv);
	exit(EXIT_FAILURE);
}
