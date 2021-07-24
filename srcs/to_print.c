/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   to_print.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:15:19 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 19:52:39 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	init_flag(t_flag to_init[9])
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

void	ft_print_flag(t_flag func[9], char flag, va_list arg, t_spec *spec)
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
