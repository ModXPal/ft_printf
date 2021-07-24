/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:18:53 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 20:23:50 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

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

void	to_print(va_list arg, const char *str, t_spec *spec)
{	
	t_flag	all_func[9];

	init_flag(all_func);
	while (*str)
	{
		init_spec(spec);
		if (*str == '%')
		{
			str++;
			parser(spec, arg, &str);
			negative_width_precision(spec);
			ft_print_flag(all_func, *str, arg, spec);
			if (*str)
				str++;
		}
		if (*str == '%')
			continue ;
		if (*str)
			spec->count += write (1, str++, 1);
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_spec	specifiers[1];

	va_start(arguments, str);
	specifiers->count = 0;
	to_print(arguments, str, specifiers);
	va_end(arguments);
	return (specifiers->count);
}
