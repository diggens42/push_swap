/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_endl_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:29:14 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:06:07 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// traverse through the string and output each character one by one
// followed by a new line

void	ft_putendl_fd(char *s, int fd)
{
	if (s != NULL)
	{
		while (*s)
		{
			write(fd, s, 1);
			s++;
		}
	}
	write(fd, "\n", 1);
}
