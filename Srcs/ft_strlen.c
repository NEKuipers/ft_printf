/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_strlen.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 11:39:18 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/20 12:03:36 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

size_t		ft_strlen(const char *s)
{
	int i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}
