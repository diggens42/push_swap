/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 14:34:32 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:38:27 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	checker_error(t_stack **a, t_stack **b, char *str)
{
	get_next_line(-1);
	free_stacks(*a, *b);
	free(str);
	write(2, "Error\n", 6);
	exit(0);
}

static void	check_and_move(t_stack **a, t_stack **b, char *str)
{
	if (!ft_strcmp(str, "pa\n"))
		push_a_checker(a, b);
	else if (!ft_strcmp(str, "pb\n"))
		push_b_checker(a, b);
	else if (!ft_strcmp(str, "sa\n"))
		swap_a_checker(a);
	else if (!ft_strcmp(str, "sb\n"))
		swap_b_checker(b);
	else if (!ft_strcmp(str, "ss\n"))
		swap_both_checker(a, b);
	else if (!ft_strcmp(str, "ra\n"))
		rotate_a_checker(a);
	else if (!ft_strcmp(str, "rb\n"))
		rotate_b_checker(b);
	else if (!ft_strcmp(str, "rr\n"))
		rotate_both_checker(a, b);
	else if (!ft_strcmp(str, "rra\n"))
		reverse_rotate_a_checker(a);
	else if (!ft_strcmp(str, "rrb\n"))
		reverse_rotate_b_checker(b);
	else if (!ft_strcmp(str, "rrr\n"))
		reverse_rotate_both_checker(a, b);
	else
		checker_error(a, b, str);
}

static void	read_lines(t_stack **a, t_stack **b)
{
	char	*str;

	str = get_next_line(0);
	while (str != NULL)
	{
		check_and_move(a, b, str);
		free(str);
		str = get_next_line(0);
	}
	if (is_sorted(*a) && *b == NULL)
		ft_putstr("OK\n");
	else
		ft_putstr("KO\n");
	free_stacks(*a, *b);
}

int	main(int argc, char **argv)
{
	t_stack	*a;
	t_stack	*b;
	bool	split;

	a = NULL;
	b = NULL;
	split = false;
	if (argc < 2)
		return (1);
	check_empty_string(argv);
	if (argc == 2)
	{
		split = true;
		argv = ft_split(argv[1], ' ');
		argc = update_argc(argv);
	}
	init_stack(argc, argv, &a, split);
	check_duplicates(argv, a, split);
	read_lines(&a, &b);
	return (0);
}
