/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putunsigned_fd.c                                :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 11:59:36 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/10 11:42:14 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

void	ft_putunsigned_fd(unsigned n, int fd, int *rv)
{
	if (n > 9)
		ft_putunsigned_fd(n / 10, fd, rv);
	ft_putchar_fd_count((char)(n % 10 + 48), fd, rv);
}
