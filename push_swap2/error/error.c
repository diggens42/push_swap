/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/26 20:55:50 by fwahl             #+#    #+#             */
/*   Updated: 2024/01/26 20:56:32 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"


void	check_stacks(t_stack_node *a, t_stack_node *b)
{
	check_duplicates(a, b);
	check_int_limits(a, b);
}

void	check_argv(char *argv)
{
	wrong_input_check(argv);
	check_empty_string(argv);
}