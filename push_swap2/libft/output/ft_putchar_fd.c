/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_put_char_fd.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fwahl <fwahl@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 18:22:12 by fwahl             #+#    #+#             */
/*   Updated: 2023/11/05 00:06:42 by fwahl            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// write a single char 'c' to the given file descriptor 'fd'
// fd: 0 standard input (stdin), 1 standard output (stdout), 
//     2 standard error (stderror)

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}
