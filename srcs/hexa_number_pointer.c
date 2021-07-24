/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hexa_number.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:30:28 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 20:08:18 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_hexa_len(t_spec *spec, unsigned int nb)
{
	int	nb_len;

	nb_len = ft_nblenbase(nb);
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
	if (nb == 0 && spec->dot && !spec->precision && spec->width)
		spec->put_space++;
}

void	ft_putnbr_upbase(va_list nb, t_spec *spec)
{
	unsigned int	num;
	int				tab[20];
	int				i;
	char			*base;

	i = 0;
	num = va_arg(nb, int);
	base = "0123456789ABCDEF";
	get_hexa_len(spec, num);
	if (num == 0 && !(spec->dot && !spec->precision))
		tab[i++] = 0;
	if (!spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
	spec->count += ft_putnchar('0', spec->put_zero);
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		spec->count += write (1, &base[tab[i]], 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
}

void	ft_putnbr_lobase(va_list nb, t_spec *spec)
{
	unsigned int	num;
	int				tab[20];
	int				i;
	char			*base;

	i = 0;
	num = va_arg(nb, int);
	base = "0123456789abcdef";
	get_hexa_len(spec, num);
	if (num == 0 && !(spec->dot && !spec->precision))
		tab[i++] = 0;
	if (!spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
	spec->count += ft_putnchar('0', spec->put_zero);
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		spec->count += write (1, &base[tab[i]], 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
}

void	get_ptr_len(t_spec *spec, unsigned long num)
{
	int	nb_len;

	nb_len = ft_nblenbase(num);
	if (num == 0 && spec->dot && !spec->precision)
		nb_len = 0;
	if (spec->precision > nb_len + 2)
		spec->put_zero = spec->precision - nb_len;
	else if (spec->width > nb_len + 2)
		spec->put_space = spec->width - nb_len - 2;
}

void	ft_put_ptr(va_list nb, t_spec *spec)
{
	unsigned long	num;
	int				tab[20];
	int				i;
	char			*base;
	unsigned long	tmp;

	i = 0;
	num = va_arg(nb, long int);
	tmp = num;
	base = "0123456789abcdef";
	get_ptr_len(spec, num);
	if (!spec->dash && spec->precision < ft_nblenbase(num))
		spec->count += ft_putnchar(' ', spec->put_space);
	if (num == 0 && !(spec->dot && !spec->precision))
		tab[i++] = 0;
	spec->count += write (1, "0x", 2);
	if (spec->precision > ft_nblenbase(num))
			spec->count += ft_putnchar('0', spec->put_zero);
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		spec->count += write (1, &base[tab[i]], 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
}
