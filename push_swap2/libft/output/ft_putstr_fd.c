/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:24:06 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:04:36 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// traverse through the string and output each character one by one

void	ft_putstr_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
}
