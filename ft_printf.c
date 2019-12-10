/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/18 09:44:57 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/10 15:49:37 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "Libft/libft.h"
#include <stdio.h>

void	parse_length(t_flags *flags, char **start)
{
	while (*start)
	{
		if (**start == 'h' && ((**start) + 1) == 'h')
		{
			flags->length = 'H';
			(*start)++;
		}
		else if (**start == 'h')
			flags->length = 'h';
		else if (**start == 'l' && ((**start) + 1) == 'l')
		{
			flags->length = 'L';
			(*start)++;
		}
		else if (**start == 'l')
			flags->length = 'l';
		else
			break ;
		(*start)++;
	}
}

void	parse_precision(t_flags *flags, char **start, va_list list)
{
	if (**start != '.')
		return ;
	else
	{
		(*start)++;
		while (**start)
		{
			if (**start == '*')
			{
				flags->precision = va_arg(list, int);
				return ;
			}
			else if (**start >= 0 || **start <= 9)
			{
				flags->precision = ft_atoi(*start);
				break ;
			}
			else
				break ;
			(*start)++;
		}
		while (ft_isdigit(**start))
			(*start)++;
	}
}

void	parse_width(t_flags *flags, char **start, va_list list)
{
	while (**start)
	{
		if (**start == '.')
			break ;
		if (**start == '*')
		{
			flags->width = va_arg(list, int);
			return ;
		}
		else if (**start >= 0 || **start <= 9)
		{
			flags->width = ft_atoi(*start);
			break ;
		}
		else
			break ;
		(*start)++;
	}
	while (ft_isdigit(**start))
		(*start)++;
}

void	parse_flags(t_flags *flags, char **start, va_list list)
{
	while (*start)
	{
		if (**start == '+')
			flags->plus = 1;
		else if (**start == '0')
			flags->zero = 1;
		else if (**start == ' ')
			flags->plus = 2;
		else if (**start == '-')
			flags->leftj = 1;
		else if (**start == '#')
			flags->hash = 1;
		else
			break ;
		(*start)++;
	}
	parse_width(flags, start, list);
	parse_precision(flags, start, list);
	parse_length(flags, start);
}

int		parse_spec(char **start, t_flags *flags, va_list list, int *rv)
{
	parse_flags(flags, start, list);
	while (**start != 's' && **start != 'c' && **start != 'i' && **start != 'd'
		&& **start != 'x' && **start != 'X' && **start != 'u' && **start != 'p'
		&& **start != 'n')
		(*start)++;
	if (**start == 's')
		ft_putstr_fd_count(va_arg(list, char *), 1, rv);
	else if (**start == 'c')
		ft_putchar_fd_count(va_arg(list, int), 1, rv);
	else if (**start == 'i' || **start == 'd')
		ft_putnbr_fd_count(va_arg(list, int), 1, rv);
	else if (**start == 'x')
		ft_putnbr_hex_fd_lower(va_arg(list, unsigned long), 1, rv);
	else if (**start == 'X')
		ft_putnbr_hex_fd_upper(va_arg(list, unsigned long), 1, rv);
	else if (**start == 'u')
		ft_putunsigned_fd(va_arg(list, unsigned), 1, rv);
	else if (**start == 'p')
	{
		ft_putstr_fd_count("0x", 1, rv);
		ft_putnbr_hex_fd_lower(va_arg(list, unsigned long), 1, rv);
	}
	//else if (**start == 'n')
	else
		return (0);
	return (1);
}

int		ft_printf(const char *input, ...)
{
	t_flags	flags;
	va_list list;
	int		rv;

	rv = 0;
	va_start(list, input);
	while (*input != '\0')
	{
		if (*input != '%')
			ft_putchar_fd_count(*input, 1, &rv);
		else
		{
			input++;
			if (*input == '%')
				ft_putstr_fd_count("%", 1, &rv);
			else
			{
				ft_bzero(&flags, (sizeof(t_flags)));
				parse_spec((char **)&input, &flags, list, &rv);
			}
		}
		input++;
	}
	va_end(list);
	return (rv);
}

int		main(void)
{
	char	*a;
	int		rv;

	/*rv = ft_printf("werkt een character? %c%c!\n", 'j', 'a');
	printf("return value is %d\n", rv);
	rv = ft_printf("werkt een string?   %s\n", "ook!");
	printf("return value is %d\n", rv);
	rv = ft_printf("werkt een integer met i :%i of d: %d?\n", 42, 42);
	printf("return value is %d\n", rv);
	rv = ft_printf("werkt een unsigned?: %u\n", 421);
	printf("return value is %d\n", rv);
	rv = ft_printf("werkt hex?: uppercase %X, lowercase %x\n", 422560, 422560);
	printf("return value is %d\n", rv);
	rv = ft_printf("en nu een pointer address? %p\n", a);
	printf("return value is %d\n", rv);*/
	ft_printf("Testing: %12.200hhs\n", "Alleen dit en niks anders");
	return (0);
}
