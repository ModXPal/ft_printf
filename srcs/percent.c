/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   percent.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 17:43:01 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 19:00:34 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	get_percent_len(t_spec *spec)
{
	if (spec->width > 1 && spec->zero)
		spec->put_zero = spec->width - 1;
	else if (spec->width > 1 && spec->dot && !spec->precision)
		spec->put_space = spec->width - 1;
	else if (spec->width > 1 && !spec->precision)
		spec->put_space = spec->width - 1;
	else if (spec->dot && spec->width > spec->precision && spec->precision <= 1)
		spec->put_space = spec->width - 1;
	else if (spec->width > 1 && spec->precision > 1)
		spec->put_space = spec->width - 1;
}

void	ft_put_percent(va_list perc, t_spec *spec)
{
	(void)perc;
	get_percent_len(spec);
	if (!spec->dash)
	{
		spec->count += ft_putnchar('0', spec->put_zero);
		spec->count += ft_putnchar(' ', spec->put_space);
	}
	spec->count += write (1, "%", 1);
	if (spec->dash)
		spec->count += ft_putnchar(' ', spec->put_space);
}
