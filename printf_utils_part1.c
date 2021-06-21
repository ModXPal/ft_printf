/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:32:40 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/18 18:09:21 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list str)
{
	char	*test;
	int		count;

	count = 0;
	test = va_arg(str, char *);
	while (*test)
		count += write(1, test++, 1);
	return (count);
}

int	ft_putnbr(va_list nb)
{
	long	num;
	int		tab[20];
	int		i;
	int		count;

	i = 0;
	count = 0;
	num = va_arg(nb, int);
	if (num < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		count += write (1, &tab[i], 1);
	return (count);
}

int	ft_putnbr_unsigned(va_list nb)
{
	long unsigned	num;
	int				tab[20];
	int				i;
	int				count;

	i = 0;
	count = 0;
	num = va_arg(nb, unsigned int);
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		count += write (1, &tab[i], 1);
	return (count);
}

int	ft_putnbr_upbase(va_list nb)
{
	long	num;
	int		tab[20];
	int		i;
	int		count;
	char	*base;

	i = 0;
	count = 0;
	num = va_arg(nb, int);
	base = "0123456789ABCDEF";
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

int	ft_putnbr_lobase(va_list nb)
{
	long	num;
	int		tab[20];
	int		i;
	int		count;
	char	*base;

	i = 0;
	count = 0;
	num = va_arg(nb, int);
	base = "0123456789abcdef";
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
