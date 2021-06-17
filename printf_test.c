/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:36:36 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/17 16:06:54 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putstr(va_list str)
{
	char *test = va_arg(str, char *);
	while (*test)
		write(1, test++, 1);
}

void	ft_putnbr(va_list nb)
{
	long num;
	int	tab[20];
	int i;

	i = 0;
	num = va_arg(nb, int);
	if (nb < 0)
	{
		num *= -1;
		write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		write (1, &tab[i], 1); 
}

void	ft_putchar(va_list c)
{
	char to_print;

	to_print = va_arg(c, int);
	write (1, &to_print, 1);
}

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
	to_init[6].func = NULL;
	to_init[7].flag = 'p';
	to_init[7].func = NULL;
	to_init[8].flag = 'i';
	to_init[8].func = NULL;
	to_init[9].flag = 'u';
	to_init[9].func = NULL;
	to_init[10].flag = 'x';
	to_init[10].func = NULL;
	to_init[11].flag = 'X';
	to_init[11].func = NULL;
	to_init[12].flag = '%';
	to_init[12].func = NULL;
	to_init[13].flag = 0;
}

int		ft_printf(const char *str, ...)
{
	va_list arguments;
	t_flag	all_func[20];
	int i;

	i = 0;
	init_flag(all_func);
	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			while (all_func[i].flag != 0)
			{
				if (all_func[i].flag == *str)
				{
					all_func[i].func(arguments);
					i = 0;
					break;
				}
				i++;
			}
		str++;
		}
		write (1, str, 1);
		str++;
	}
	va_end(arguments);
	return (1);
}

int	main(void)
{
	char *str = "test";
	char *str2 = "l'annee";
	char *str3 = "ici";
	char *print = "rien";
	char c = 'e';
	int num = 2021;
	int num1 = 100;

	ft_printf("L%c %de m%cill%cur %s d%c %s %d s%c trouv%c %s\n", c, num1, c, c, str, c, str2, num, c, c, str3);
	printf("test flag 2 ---> %s\n", print);
	printf("test flag point s ---> %s. \n", print);
	printf("test flag point d ---> %d \n", num);
}
