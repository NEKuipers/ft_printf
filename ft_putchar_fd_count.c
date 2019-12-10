/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putchar_fd_count.c                              :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 10:54:38 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/10 11:30:11 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

void	ft_putchar_fd_count(char c, int fd, int *rv)
{
	write(fd, &c, 1);
	*rv += 1;
}
