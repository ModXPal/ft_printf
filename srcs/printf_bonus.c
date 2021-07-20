/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/13 12:24:01 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/20 11:34:41 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_flag(t_flag to_init[20])
{
	to_init[0].flag = 'd';
	to_init[0].func = ft_putnbr;
	to_init[1].flag = 's';
	to_init[1].func = ft_putstring;
	to_init[2].flag = 'c';
	to_init[2].func = ft_putchar;
	to_init[3].flag = 'x';
	to_init[3].func = ft_putnbr_lobase;
	to_init[4].flag = 'p';
	to_init[4].func = ft_put_ptr;
	to_init[5].flag = 'i';
	to_init[5].func = ft_putnbr;
	to_init[6].flag = 'u';
	to_init[6].func = ft_putnbr_unsigned;
	to_init[7].flag = 'X';
	to_init[7].func = ft_putnbr_upbase;
	to_init[8].flag = '%';
	to_init[8].func = ft_put_percent;
	to_init[9].flag = 0;
}

void	ft_print_flag(t_flag func[20], char flag, va_list arg, t_spec *spec)
{
	int	i;

	i = 0;
	while (func[i].flag)
	{
		if (func[i].flag == flag)
		{
			func[i].func(arg, spec);
			break ;
		}
		i++;
	}
}

void	init_spec(t_spec *spec)
{
	spec->dot = 0;
	spec->width = 0;
	spec->dash = 0;
	spec->zero = 0;
	spec->precision = 0;
	spec->wildcard = 0;
	spec->put_zero = 0;
	spec->put_space = 0;
}

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

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_flag	all_func[20];
	t_spec	specifiers[1];

	init_flag(all_func);
	va_start(arguments, str);
	specifiers->count = 0;
	while (*str)
	{
		init_spec(specifiers);
		if (*str == '%')
		{
			parser(specifiers, arguments, &str);
			ft_print_flag(all_func, *str, arguments, specifiers);
			str++;
		}
		if (*str == '%')
			continue ;
		if (*str)
			specifiers->count += write (1, str, 1);
		if (*str)
			str++;
	}
	va_end(arguments);
	return (specifiers->count);
}
