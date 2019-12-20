/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_bzero.c                                         :+:    :+:            */
/*                                                     +:+                    */
/*   By: nkuipers <marvin@codam.nl>                   +#+                     */
/*                                                   +#+                      */
/*   Created: 2019/10/28 15:32:32 by nkuipers       #+#    #+#                */
/*   Updated: 2019/12/20 11:45:01 by nkuipers      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "../Includes/ft_printf.h"

void	ft_bzero(void *s, size_t n)
{
	size_t	i;

	i = 0;
	while (n > i)
	{
		((char*)s)[i] = 0;
		i++;
	}
}
