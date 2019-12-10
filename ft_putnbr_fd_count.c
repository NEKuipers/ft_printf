/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_fd_count.c                               :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/10 11:14:21 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/10 11:41:33 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

void	ft_putnbr_fd_count(int n, int fd, int *rv)
{
	if (n == -2147483648)
	{
		write(fd, "-2", 2);
		n = 147483648;
		*rv += 2;
	}
	if (n < 0)
	{
		ft_putchar_fd_count('-', fd, rv);
		n = n * -1;
	}
	if (n > 9)
		ft_putnbr_fd_count(n / 10, fd, rv);
	ft_putchar_fd_count((char)(n % 10 + 48), fd, rv);
}
