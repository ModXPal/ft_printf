/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:32:40 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/28 16:20:02 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_len(t_spec *spec, char *str)
{
	int len;

	len = 0;
	if (spec->width > ft_strlen(str) && spec->dot && !spec->precision)
		len = spec->width;
	else if (spec->width > ft_strlen(str) && !spec->precision)
		len = spec->width - ft_strlen(str);
	else if (spec->dot && spec->width > spec->precision && spec->precision <= ft_strlen(str))
		len = spec->width - spec->precision; 
	else if (spec->width > ft_strlen(str) && spec->precision > ft_strlen(str))
		len = spec->width - ft_strlen(str);
	//printf("width = %d\n", spec->width);
	//printf("precision= %d\n", spec->precision);
	//printf("length = %d\n", ft_strlen(str));
	//printf("len = %d\n", len);
	return (len);
}

int	ft_putstr(va_list str, t_spec *specifiers)
{
	char	*string;
	int		count;
	int i;
	int len;

	count = 0;
	i = 0;
	string = va_arg(str, char *);
	if (!string)
		string = "(null)";
	len = get_len(specifiers, string);
	if (!specifiers->dash)
		count += ft_putnchar(' ', len);
	if (specifiers->dot)
		while (string[i] && i < specifiers->precision)
			count += write(1, &string[i++], 1);
	else
		while (string[i])
			count += write(1, &string[i++], 1);
	if (specifiers->dash)
		count += ft_putnchar(' ', len);
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
