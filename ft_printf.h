/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.h                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <nkuipers@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/11/27 14:19:34 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/10 15:44:36 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>
# include "Libft/libft.h"

typedef struct	s_flags
{
	int		width;
	int		precision;
	int		leftj;
	int		plus;
	int		zero;
	int		hash;
	char	length;
}				t_flags;

int				ft_printf(const char *str, ...);
int				parse_spec(char **start, t_flags *flags,
				va_list list, int *pc);
void			parse_flags(t_flags *flags, char **start, va_list list);
void			parse_length(t_flags *flags, char **start);
void			parse_precision(t_flags *flags, char **start, va_list list);
void			parse_width(t_flags *flags, char **start, va_list list);

void			ft_putchar_fd_count(char c, int fd, int *rv);
void			ft_putnbr_fd_count(int n, int fd, int *rv);
void			ft_putnbr_hex_fd_lower(unsigned long nb, int fd, int *rv);
void			ft_putnbr_hex_fd_upper(unsigned long nb, int fd, int *rv);
void			ft_putstr_fd_count(char *s, int fd, int *rv);
void			ft_putunsigned_fd(unsigned n, int fd, int *rv);

#endif
