/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*   Updated: 2021/06/21 11:53:03 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_flag(t_flag to_init[20])
{
	to_init[0].flag = 'd';
	to_init[0].func = ft_putnbr;
	to_init[1].flag = 's';
	to_init[1].func = ft_putstr;
	to_init[2].flag = 'c';
	to_init[2].func = ft_putchar;
	to_init[3].flag = '.';
	to_init[3].func = NULL;
	to_init[4].flag = '-';
	to_init[4].func = NULL;
	to_init[5].flag = '*';
	to_init[5].func = NULL;
	to_init[6].flag = 'x';
	to_init[6].func = ft_putnbr_lobase;
	to_init[7].flag = 'p';
	to_init[7].func = ft_put_ptr;
	to_init[8].flag = 'i';
	to_init[8].func = ft_putnbr;
	to_init[9].flag = 'u';
	to_init[9].func = ft_putnbr_unsigned;
	to_init[10].flag = 'X';
	to_init[10].func = ft_putnbr_upbase;
	to_init[11].flag = '%';
	to_init[11].func = ft_put_percent;
	to_init[12].flag = 0;
}

int	ft_print_flag(t_flag func[20], char flag, va_list arg, t_spec *specifiers)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (func[i].flag)
	{
		if (func[i].flag == flag)
		{
			count += func[i].func(arg, specifiers);
			break ;
		}
		i++;
	}
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arguments;
	t_flag	all_func[20];
	int		count;
	t_spec	specifiers[1];

	count = 0;
	init_flag(all_func);
	va_start(arguments, str);
	specifiers->dot = 0;
	specifiers->width = 0;
	specifiers->dash = 0;
	specifiers->zero = 0;
	specifiers->after_dot = 0;
	specifiers->before_dot = 0;
	specifiers->precision = 0;
	specifiers->wildcard = 0;
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (*str == '-')
			{
				specifiers->dash = 1;
				str++;
			}
			if (*str == '*')
			{
				specifiers->width = va_arg(arguments, int);
				str++;
			}
			while (*str >= '0' && *str <= '9')
				specifiers->width = specifiers->width * 10 + *str++ - 48; 
			if (*str == '.')
			{
				specifiers->dot = 1;
				str++;
			}
			if (specifiers->width && specifiers->dot)
			{
				specifiers->before_dot = 1;
			}
			if (*str == '*')
			{
				specifiers->precision = va_arg(arguments, int);
				str++;
			}
			if (*str == '0')
			{
				specifiers->zero = 1;
			}
			if (specifiers->width < 0)
			{
				specifiers->width *= -1;
				specifiers->dash = 1;
			}
			if (specifiers->precision < 0)
			{
				specifiers->precision *= -1;
				specifiers->dash = 1;
			}
			while (*str >= '0' && *str <= '9')
				specifiers->precision = specifiers->precision * 10 + *str++ - 48; 
			count += ft_print_flag(all_func, *str, arguments, specifiers);
			str++;
		}	
		if (*str)
			count += write (1, str, 1);
		if (*str)
			str++;
		specifiers->dot = 0;
		specifiers->width = 0;
		specifiers->dash = 0;
		specifiers->zero = 0;
		specifiers->after_dot = 0;
		specifiers->before_dot = 0;
		specifiers->precision = 0;
	}
		va_end(arguments);
	return (count);
}
