/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:17:47 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 16:18:39 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	negative_width_precision(t_spec *spec)
{
	if (spec->width < 0)
	{
		spec->width *= -1;
		spec->dash = 1;
		spec->zero = 0;
	}
	if (spec->precision < 0)
	{
		spec->precision = 0;
		spec->dot = 0;
	}
}

void	is_dash_zero(t_spec *spec, const char **str)
{
	if (**str == '-')
	{
		spec->dash = 1;
		while (**str == '-' || **str == '0')
			(*str)++;
	}
	else if (**str == '0')
	{
		spec->zero = 1;
		while (**str == '0' || **str == '-')
		{
			if (**str == '-' || spec->dash)
			{
				spec->zero = 0;
				spec->dash = 1;
			}
			(*str)++;
		}
	}
}

void	parser(t_spec *spec, va_list arguments, const char **str)
{
	(*str)++;
	if (**str == '-' || **str == '0')
		is_dash_zero(spec, str);
	if (**str == '*')
	{
		spec->width = va_arg(arguments, int);
		(*str)++;
	}
	if (ft_isdigit(**str))
		spec->width = ft_atoi(str);
	if (**str == '.')
	{
		spec->dot = 1;
		(*str)++;
	}
	if (**str == '*')
	{
		spec->precision = va_arg(arguments, int);
		(*str)++;
	}
	if (ft_isdigit(**str))
		spec->precision = ft_atoi(str);
	negative_width_precision(spec);
}
