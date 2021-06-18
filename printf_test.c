/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:36:36 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/18 16:30:21 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(va_list str)
{
	char *test;
	int	count;
		
	count = 0;
	test = va_arg(str, char *);
	while (*test)
		count += write(1, test++, 1);
	return (count);
}

int		ft_putnbr(va_list nb)
{
	long num;
	int	tab[20];
	int i;
	int count;

	i = 0;
	count = 0;
	num = va_arg(nb, int);
	if (nb < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		count += write (1, &tab[i], 1); 
	return (count);
}

int		ft_putnbr_unsigned(va_list nb)
{
	long unsigned num;
	int	tab[20];
	int i;
	int count;

	i = 0;
	count = 0;
	num = va_arg(nb, unsigned int);
	if (nb < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 10 + 48;
		num /= 10;
	}
	while (i--)
		count += write (1, &tab[i], 1); 
	return (count);
}

int		ft_putnbr_upbase(va_list nb)
{
	long num;
	int	tab[20];
	int i;
	int count;
	char *base;

	i = 0;
	count = 0;
	num = va_arg(nb, int);
	base = "0123456789ABCDEF";
	if (nb < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		count += write (1, &base[tab[i]], 1); 
	return (count);
}

int		ft_putnbr_lobase(va_list nb)
{
	long	num;
	int	tab[20];
	int	i;
	int	count;
	char	*base;

	i = 0;
	count = 0;
	num = va_arg(nb, int);
	base = "0123456789abcdef"; 
	if (nb < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		count += write (1, &base[tab[i]], 1); 
	return (count);
}

int		ft_put_ptr(va_list nb)
{
	long long	num;
	int		tab[20];
	int		i;
	int		count;
	char		*base;

	i = 0;
	count = 0;
	num = va_arg(nb, long int);
	base = "0123456789abcdef"; 
	count += write (1, "0x", 2);
	if (nb < 0)
	{
		num *= -1;
		count += write (1, "-", 1);
	}
	while (num > 0)
	{
		tab[i++] = num % 16;
		num /= 16;
	}
	while (i--)
		count += write (1, &base[tab[i]], 1); 
	return (count);
}
int	ft_putchar(va_list c)
{
	char	to_print;
	int		count;

	count = 0;
	to_print = va_arg(c, int);
	count += write (1, &to_print, 1);
	return (count);
}

int	ft_put_percent(va_list nul)
{
	return (write (1, "%", 1));
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

int		ft_print_flag(t_flag func[20], char flag, va_list arg)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (func[i].flag != 0)
	{
		if (func[i].flag == flag)
		{
			count += func[i].func(arg);
			i = 0;
			break;
		}
		i++;
	}
	return (count);
}

int		ft_printf(const char *str, ...)
{
	va_list arguments;
	t_flag	all_func[20];
	int		count;

	count = 0;
	init_flag(all_func);
	va_start(arguments, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			count += ft_print_flag(all_func, *str, arguments);
			str++;
		}	
		count += write (1, str, 1);
		str++;
	}
	va_end(arguments);
	return (count);
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
	int ici = 0x12;
	int *ptr;
	unsigned int nb_un;

	ptr = &num;
	nb_un = 4294967295;
	printf("%d\n", ft_printf("L%c %de m%cill%cur %s d%c %s %d s%c trouv%c %s\n", c, num1, c, c, str, c, str2, num, c, c, str3));
	printf("test rp %%.2s ---> %.2s. \n", print);
	printf("test rp %%.6d ---> %.6d \n", num);
	printf("test rp %%-6d ----> %-6d |\n", num);
	printf("test rp %%i hexa-----> %i\n", ici);
	printf("test rp %%i hexa-----> %i\n", ici);
	ft_printf("test mp %%d hexa-----> %d\n", ici);
	ft_printf("test mp %%i hexa-----> %i\n", ici);
	ft_printf("test mp %%p address ---> %p\n", ptr);
	printf("test rp %%p address ---> %p\n", ptr);
	printf("test rp %%-15p ----> %-15p|\n", ptr);
	printf("test rp %%u ----> %u\n", nb_un);
	ft_printf("test mp %%u ----> %u\n", nb_un);

}
