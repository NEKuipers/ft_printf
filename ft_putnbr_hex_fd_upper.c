/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_hex_fd_upper.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 11:41:50 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/10 11:43:24 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

void	ft_putnbr_hex_fd_upper(unsigned long nb, int fd, int *rv)
{
	if (nb > 15)
		ft_putnbr_hex_fd_upper((nb / 16), fd, rv);
	if (nb % 16 < 10)
		ft_putchar_fd_count(('0' + (nb % 16)), fd, rv);
	else
		ft_putchar_fd_count((55 + (nb % 16)), fd, rv);
}
