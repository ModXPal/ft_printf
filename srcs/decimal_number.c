/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   decimal_number.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:29:32 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 16:30:17 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_nbr_len(t_spec *spec, int nb)
{
	int	nb_len;

	nb_len = ft_nblen(nb);
	if (nb < 0 && spec->dot)
		nb_len--;
	if (nb == 0 && !spec->dot && spec->zero && spec->width)
		spec->put_zero = spec->width - 1;
	else if (spec->precision >= ft_nblen(nb) && spec->width > spec->precision)
	{
		spec->put_zero = spec->precision - nb_len;
		spec->put_space = spec->width - spec->precision;
	}
	else if (spec->precision >= ft_nblen(nb) && spec->width <= spec->precision)
		spec->put_zero = spec->precision - nb_len;
	else if (spec->width > nb_len && spec->zero && !spec->dot)
		spec->put_zero = spec->width - nb_len;
	else if (spec->precision <= nb_len && spec->width > nb_len)
		spec->put_space = spec->width - nb_len;
	if (nb < 0 && spec->put_space && spec->dot)
		spec->put_space--;
	if (nb == 0 && !spec->dot && spec->put_space)
		spec->put_space--;
}

void	print_before(t_spec *spec, int num)
{
	if (!spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
	if (num < 0 && spec->put_zero)
		spec->count += write (1, "-", 1);
	spec->count += ft_putnchar('0', spec->put_zero);
	if (num < 0 && !spec->put_zero)
		spec->count += write (1, "-", 1);
}

void	ft_putnbr(va_list nb, t_spec *spec)
{
	long	num;
	long	tab[20];
	int		i;

	i = 0;
	num = va_arg(nb, int);
	get_nbr_len(spec, num);
	if (num == 0 && !spec->dot)
	{
		tab[0] = 48;
		i++;
	}
	print_before(spec, num);
	if (num < 0)
		num *= -1;
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

void	get_unbr_len(t_spec *spec, unsigned int nb)
{
	int	nb_len;

	nb_len = ft_unblen(nb);
	if (nb == 0 && !spec->dot && spec->zero && spec->width)
		spec->put_zero = spec->width - 1;
	else if (spec->precision >= nb_len && spec->width > spec->precision)
	{
		spec->put_zero = spec->precision - nb_len;
		spec->put_space = spec->width - spec->precision;
	}
	else if (spec->precision >= nb_len && spec->width <= spec->precision)
		spec->put_zero = spec->precision - nb_len;
	else if (spec->width > nb_len && spec->zero && !spec->dot)
		spec->put_zero = spec->width - nb_len;
	else if (spec->precision <= nb_len && spec->width > nb_len)
		spec->put_space = spec->width - nb_len;
	if (nb == 0 && !spec->dot && spec->put_space)
		spec->put_space--;
}

void	ft_putnbr_unsigned(va_list nb, t_spec *spec)
{
	int				i;
	unsigned long	num;
	unsigned long	tab[20];

	i = 0;
	num = va_arg(nb, unsigned int);
	get_unbr_len(spec, num);
	if (num == 0 && !spec->dot)
	{
		tab[0] = 48;
		i++;
	}
	if (!spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
	spec->count += ft_putnchar('0', spec->put_zero);
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
