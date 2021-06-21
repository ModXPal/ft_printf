/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:40:30 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/18 18:03:38 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_ptr(va_list nb)
{
	long long	num;
	int			tab[20];
	int			i;
	int			count;
	char		*base;

	i = 0;
	count = 0;
	num = va_arg(nb, long int);
	base = "0123456789abcdef";
	count += write (1, "0x", 2);
	if (num < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		count += write (1, &base[tab[i]], 1);
	return (count);
}

int	ft_putchar(va_list c)
{
	char	to_print;
	int		count;

	count = 0;
	to_print = va_arg(c, int);
	count += write (1, &to_print, 1);
	return (count);
}

int	ft_put_percent(va_list nul)
{
	(void)nul;
	return (write (1, "%", 1));
}
