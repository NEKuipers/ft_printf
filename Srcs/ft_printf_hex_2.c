/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_hex_2.c                                  :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/20 10:20:30 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/20 12:27:17 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_puthex_lower_count(unsigned int nbr, int *rv)
{
	unsigned int	tmp;
	unsigned int	len;
	char			*hex;

	hex = "0123456789abcdef";
	tmp = nbr;
	len = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		len *= 16;
	}
	tmp = nbr;
	while (len)
	{
		ft_putchar_fd_count(hex[nbr / len], 1, rv);
		nbr %= len;
		len /= 16;
	}
}

void	ft_puthex_upper_count(unsigned int nbr, int *rv)
{
	unsigned int	tmp;
	unsigned int	len;
	char			*hex;

	hex = "0123456789ABCDEF";
	tmp = nbr;
	len = 1;
	while (tmp / 16)
	{
		tmp /= 16;
		len *= 16;
	}
	tmp = nbr;
	while (len)
	{
		ft_putchar_fd_count(hex[nbr / len], 1, rv);
		nbr %= len;
		len /= 16;
	}
}

int		ft_nbrlen_hex(unsigned int nbr)
{
	unsigned int	tmp;
	int				len;

	tmp = nbr;
	len = 0;
	if (nbr == 0)
		len++;
	while (tmp)
	{
		tmp = tmp / 16;
		len++;
	}
	return (len);
}
