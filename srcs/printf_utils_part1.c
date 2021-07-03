/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:32:40 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/03 11:14:13 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	get_str_len(t_spec *spec, char *str)
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
	return (len);
}

void	ft_putstr(va_list str, t_spec *spec)
{
	char	*string;
	int i;
	int len;

	i = 0;
	string = va_arg(str, char *);
	if (!string)
		string = "(null)";
	len = get_str_len(spec, string);
	if (!spec->dash)
		spec->count += ft_putnchar(' ', len);
	if (spec->dot)
		while (string[i] && i < spec->precision)
			spec->count += write(1, &string[i++], 1);
	else
		while (string[i])
			spec->count += write(1, &string[i++], 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', len);
}

void	get_nbr_len(t_spec *spec, int nb)
{
	int nb_len;

	nb_len = ft_nblen(nb);
	if (nb < 0)
		nb_len--;
	if (nb == 0 && spec->precision)
	{
		spec->put_zero = spec->precision;
		if (spec->width > spec->precision)
			spec->put_space = spec->width - spec->precision;
	}
	else if (spec->precision >= ft_nblen(nb) && spec->width > spec->precision) 
	{
		spec->put_zero = spec->precision - nb_len; 
		spec->put_space = spec->width - spec->precision;
	}
	else if (spec->precision > ft_nblen(nb) && spec->width < spec->precision)
		spec->put_zero = spec->precision - nb_len;
	else if (spec->width > ft_nblen(nb) && spec->zero && !spec->dot)
		spec->put_zero = spec->width - nb_len;
	else if (spec->precision <= ft_nblen(nb) && spec->width > ft_nblen(nb))
		spec->put_space = spec->width - nb_len;
	if (nb < 0 && spec->put_space)
		spec->put_space--;
	if (nb < 0 && spec->put_zero && spec->width > spec->precision && spec->precision > ft_nblen(nb))
		spec->put_zero--;
}

void	ft_putnbr(va_list nb, t_spec *spec)
{
	long	num;
	long	tab[20];
	int		i;
	long	tmp;

	i = 0;
	num = va_arg(nb, int);
	tmp = num;
	get_nbr_len(spec, num);
	if (num < 0)
		num *= -1;
	if (num == 0 && !spec->dot)
	{
		tab[0] = 48;
		i++;
	}
	if (!spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
	if (tmp < 0 && spec->put_zero)
		spec->count += write (1, "-", 1);
	spec->count += ft_putnchar('0', spec->put_zero);
	if (tmp < 0 && !spec->put_zero)
		spec->count += write (1, "-", 1);
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		spec->count += write (1, &tab[i], 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
}

void	ft_putnbr_unsigned(va_list nb, t_spec *spec)
{
	long unsigned	num;
	int				tab[20];
	int				i;

	(void)spec;
	i = 0;
	spec->count = 0;
	num = va_arg(nb, unsigned int);
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		spec->count += write (1, &tab[i], 1);
}

void	ft_putnbr_upbase(va_list nb, t_spec *spec)
{
	long	num;
	int		tab[20];
	int		i;
	char	*base;

	(void)spec;
	i = 0;
	num = va_arg(nb, int);
	base = "0123456789ABCDEF";
	if (num < 0)
	{
		num *= -1;
		spec->count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		spec->count += write (1, &base[tab[i]], 1);
}

void	ft_putnbr_lobase(va_list nb, t_spec *spec)
{
	long	num;
	int		tab[20];
	int		i;
	char	*base;

	(void)spec;
	i = 0;
	num = va_arg(nb, int);
	base = "0123456789abcdef";
	if (num < 0)
	{
		num *= -1;
		spec->count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		spec->count += write (1, &base[tab[i]], 1);
}
