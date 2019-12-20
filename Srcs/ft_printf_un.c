/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf_un.c                                     :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/12/19 16:16:09 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/20 11:42:33 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

int			ft_nbrlen_un(unsigned int nbr)
{
	int length;
	int nb;

	nb = nbr;
	length = (nb < 0) ? 1 : 0;
	if (nb == 0)
		return (1);
	while (nb != 0)
	{
		nb /= 10;
		length++;
	}
	return (length);
}

void		ft_putunsigned_fd(unsigned n, int fd, int *rv)
{
	if (n > 9)
		ft_putunsigned_fd(n / 10, fd, rv);
	ft_putchar_fd_count((char)(n % 10 + 48), fd, rv);
}

void		prepare_un(t_flags *flags, unsigned int *nbr)
{
	if (flags->length == 'h')
		*nbr = (short)*nbr;
	else if (flags->length == 'H')
		*nbr = (char)*nbr;
	if (*nbr < 0)
	{
		flags->sign = '-';
		*nbr *= -1;
	}
	if (flags->sign != 0)
		flags->signornot = 1;
	flags->nbrlen = ft_nbrlen(*nbr);
	if (flags->precision == -1 ||
		(flags->precision < flags->nbrlen && *nbr != 0))
		flags->precision = flags->nbrlen;
}

void		printun(t_flags *flags, va_list list, int *rv)
{
	unsigned int		nbr;

	nbr = va_arg(list, unsigned int);
	prepare_un(flags, &nbr);
	if (flags->sign > 0 && (flags->leftj || flags->zero))
		ft_putchar_fd_count(flags->sign, 1, rv);
	if (flags->leftj)
	{
		padder(flags->precision, flags->length, '0', rv);
		if (flags->precision != -1)
			ft_putunsigned_fd(nbr, 1, rv);
	}
	if (flags->leftj == 0 && flags->zero == 1)
		padder(flags->width, flags->precision + flags->signornot, '0', rv);
	else
		padder(flags->width, flags->precision + flags->signornot, ' ', rv);
	if (flags->leftj == 0)
	{
		if (flags->sign && !flags->zero)
			ft_putchar_fd_count(flags->sign, 1, rv);
		padder(flags->precision, flags->nbrlen, '0', rv);
		if (flags->precision)
			ft_putunsigned_fd(nbr, 1, rv);
	}
}
