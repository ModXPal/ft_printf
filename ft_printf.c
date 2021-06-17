/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:56:03 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/17 12:42:50 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "./libft/libft.h"
#include <stdio.h>

typedef int (*func)(int);
int	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
		write(1, &str[i++], 1);
	return (i);
}

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_putnbr(int nb)
{
	long	num;

	num = nb;
	if (nb < 0)
		num *= -1;
	if (num > 10)
		ft_putnbr(num / 10);
	num = num % 10 + 48;
	write(1, &num, 1);
	return (1);
}

int	search_flag(char c, t_flag *to_search)
{
	int i;

	i = 0;
	while (to_search[i].flag != 0)
	{
		if (to_search[i].flag == c)
			return (i);
		i++;
	}
	return (-1);
}

int	main(void)
{
	char *test;
	char *s;
	char c;
	int num;
	func *put = NULL;
	t_flag all_flag[20];

	test = "Le gros %s, %c, %d.";
	s = "test";
	c = 'o';
	num = 123;
	put[0] = ft_putchar;
	put[1] = ft_putnbr;
	put[0](c);
	put[1](123);
	all_flag[0].func = (void *)ft_putstr;
	all_flag[0].flag = 's';
	all_flag[1].func = (void *)ft_putchar;
	all_flag[1].flag = 'c';
	all_flag[2].func = (void *)ft_putnbr;
	all_flag[2].flag = 'd';
	all_flag[3].flag = 0;
	while (*test)
	{
		if (*test == '%')
		{
			test++;
			if (search_flag(*test, all_flag) >= 0)
				all_flag[search_flag(*test, all_flag)].func(&c);
			test++;
		}
		write(1, test, 1);
		test++;
	}
}
