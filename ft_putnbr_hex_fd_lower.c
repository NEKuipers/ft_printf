/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_putnbr_hex_fd_lower.c                           :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/04 11:15:03 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/10 11:43:17 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

void	ft_putnbr_hex_fd_lower(unsigned long nb, int fd, int *rv)
{
	if (nb > 15)
		ft_putnbr_hex_fd_lower((nb / 16), fd, rv);
	if (nb % 16 < 10)
		ft_putchar_fd_count(('0' + nb % 16), fd, rv);
	else
		ft_putchar_fd_count((87 + nb % 16), fd, rv);

}
