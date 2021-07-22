/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 17:40:30 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/22 18:38:56 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_put_ptr(va_list nb, t_spec *spec)
{
	unsigned long	num;
	int			tab[20];
	int			i;
	char		*base;
	unsigned long 		tmp;

	i = 0;
	num = va_arg(nb, long int);
	tmp = num;
	base = "0123456789abcdef";
	if (!spec->dash && spec->width > ft_nblenbase(num) + 2 && !spec->dot)
		spec->count += ft_putnchar(' ', spec->width - ft_nblenbase(num) - 2);
	if (num == 0)
		tab[i++] = 0;
	spec->count += write (1, "0x", 2);
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		spec->count += write (1, &base[tab[i]], 1);
	if (spec->dash && spec->width > (ft_nblenbase(tmp) + 2) && !spec->dot)
		spec->count += ft_putnchar(' ', spec->width - ft_nblenbase(tmp) - 2);
}

int	get_char_len(t_spec *spec)
{
	int len;

	len = 0;
	if (spec->width > 1 && spec->dot && !spec->precision)
		len = spec->width;
	else if (spec->width > 1 && !spec->precision)
		len = spec->width - 1;
	else if (spec->dot && spec->width > spec->precision && spec->precision <= 1)
		len = spec->width - spec->precision; 
	else if (spec->width > 1 && spec->precision > 1) 
		len = spec->width - 1;
	return (len);
}

void	ft_putchar(va_list c, t_spec *spec)
{
	char	to_print;
	int	len;

	to_print = va_arg(c, int);
	len = get_char_len(spec);
	if (!spec->dash)
		spec->count += ft_putnchar(' ', len);
	spec->count += write (1, &to_print, 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', len);
}

void	ft_put_percent(va_list nul, t_spec *spec)
{
	(void)nul;
	(void)spec;
	spec->count += write (1, "%", 1);
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
		return (0);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_unblen(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (0);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_nblenbase(unsigned long int nb)
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
