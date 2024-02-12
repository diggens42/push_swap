/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 12:16:24 by fwahl             #+#    #+#             */
/*   Updated: 2024/02/12 19:35:41 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

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
	sort_check(a, b, argc, split);
	return (0);
}
