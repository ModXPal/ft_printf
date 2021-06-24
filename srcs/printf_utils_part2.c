/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:40:30 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/22 19:08:41 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_put_ptr(va_list nb, t_spec *specifiers)
{
	long long	num;
	int			tab[20];
	int			i;
	int			count;
	char		*base;
	long 		tmp;

	i = 0;
	count = 0;
	num = va_arg(nb, long int);
	tmp = num;
	base = "0123456789abcdef";
	if (!specifiers->dash && specifiers->width > ft_nblenbase(num) && !specifiers->dot)
		count += ft_putnchar(' ', specifiers->width - ft_nblenbase(num) - 2);
	count += write (1, "0x", 2);
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		count += write (1, &base[tab[i]], 1);
	if (specifiers->dash && specifiers->width > ft_nblenbase(tmp) && !specifiers->dot)
	{
		count += ft_putnchar(' ', specifiers->width - ft_nblenbase(tmp) - 2);
	}
	return (count);
}

int	ft_putchar(va_list c, t_spec *specifiers)
{
	char	to_print;
	int		count;

	(void)specifiers;
	count = 0;
	to_print = va_arg(c, int);
	count += write (1, &to_print, 1);
	return (count);
}

int	ft_put_percent(va_list nul, t_spec *specifiers)
{
	(void)nul;
	(void)specifiers;
	return (write (1, "%", 1));
}

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nblen(int nb)
{
	long num;
	int i;

	i = 0;
	num = nb;
	if (num == 0)
		return (1);
	if (num < 0)
		num *= -1;
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_nblenbase(long nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_putnchar(char c, int len)
{
	int count;

	count  = 0;
	while (len--)
		count += write (1, &c, 1);
	return (count);
}
