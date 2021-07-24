/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:18:53 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 20:09:21 by rcollas          ###   ########.fr       */
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

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_flag	all_func[9];
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
			if (*str)
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
