/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils2.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:28:02 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 16:28:26 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putnchar(char c, int len)
{
	int count;

	count  = 0;
	while (len--)
		count += write (1, &c, 1);
	return (count);
}

int	ft_isdigit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_putstr(char *str)
{
	return (write (1, str, ft_strlen(str)));
}
