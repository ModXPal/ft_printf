/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:32:40 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/22 19:08:40 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_putstr(va_list str, t_spec *specifiers)
{
	char	*string;
	int		count;
	int i;

	count = 0;
	i = 0;
	string = va_arg(str, char *);
	if (!string)
	{
		string = "(null)";
		if (specifiers->precision && !specifiers->before_dot)
			specifiers->precision = 6;
	}
	if (!specifiers->dash && specifiers->width > ft_strlen(string) && !specifiers->dot && !specifiers->precision)
		count += ft_putnchar(' ', specifiers->width - ft_strlen(string));
	else if (specifiers->before_dot && !specifiers->dash && specifiers->precision && specifiers->precision >= ft_strlen(string))
		count += ft_putnchar(' ', specifiers->width - ft_strlen(string));
	else if (specifiers->before_dot && !specifiers->dash && specifiers->precision)
		count += ft_putnchar(' ', specifiers->width - specifiers->precision);
	else if (specifiers->before_dot && !specifiers->after_dot && !specifiers->dash)
		count += ft_putnchar(' ', specifiers->width);
	if (specifiers->dot)
		while (string[i] && i < specifiers->precision)
			count += write(1, &string[i++], 1);
	else
		while (string[i])
			count += write(1, &string[i++], 1);
	if (specifiers->dash && specifiers->width > ft_strlen(string) && !specifiers->dot && !specifiers->precision)
		count += ft_putnchar(' ', specifiers->width - ft_strlen(string));
	else if (specifiers->before_dot && specifiers->dash && specifiers->precision && specifiers->precision >= ft_strlen(string))
		count += ft_putnchar(' ', specifiers->width - ft_strlen(string));
	else if (specifiers->before_dot && specifiers->dash && specifiers->precision)
		count += ft_putnchar(' ', specifiers->width - specifiers->precision);
	else if (specifiers->before_dot && !specifiers->after_dot && specifiers->dash)
		count += ft_putnchar(' ', specifiers->width);
	return (count);
}

int	ft_putnbr(va_list nb, t_spec *specifiers)
{
	long	num;
	int		tab[20];
	int		i;
	int		count;
	int		tmp;

	i = 0;
	count = 0;
	num = va_arg(nb, int);
	tmp = num;
	if (num < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	if ((specifiers->dot && specifiers->dash) ||(specifiers->dash && specifiers->zero) )
	{
		specifiers->dash = 0;
		specifiers->zero = 0;
	}
	while (i++ < specifiers->width - ft_nblen(num) && !specifiers->dash)
		if (specifiers->dot || specifiers->zero)
			count += write (1, "0", 1);
		else
			count += write (1, " ", 1);
	i = 0;
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		count += write (1, &tab[i], 1);
	if (specifiers->dash)
		while (i++ + 1 < specifiers->width - ft_nblen(tmp))
			count+= write (1, " ", 1);
	return (count);
}

int	ft_putnbr_unsigned(va_list nb, t_spec *specifiers)
{
	long unsigned	num;
	int				tab[20];
	int				i;
	int				count;

	(void)specifiers;
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

int	ft_putnbr_upbase(va_list nb, t_spec *specifiers)
{
	long	num;
	int		tab[20];
	int		i;
	int		count;
	char	*base;

	(void)specifiers;
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

int	ft_putnbr_lobase(va_list nb, t_spec *specifiers)
{
	long	num;
	int		tab[20];
	int		i;
	int		count;
	char	*base;

	(void)specifiers;
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
