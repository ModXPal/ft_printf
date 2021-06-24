/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:16:55 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/22 19:08:42 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"

int	main(void)
{
	char	*str = "test";
	char	*str2 = "l'annee";
	char	*str3 = "ici";
	char	*print = "rien";
	char	c = 'e';
	int		num = 2021;
	int		num1 = 100;
	int		ici = 0x12;
	int		*ptr;
	int 	var = 10;
	unsigned int nb_un;

	ptr = &num;
	nb_un = 4294967295;
	printf(" %.*s \n", -2, NULL);
	ft_printf(" %.*s \n", -2, NULL);
	/*
	printf("test rp %%2s -----------> %2s| \n", print);
	ft_printf("test mp %%2s -----------> %2s| \n", print);
	printf("test rp %%10s -----------> %10s| \n", print);
	ft_printf("test mp %%10s -----------> %10s| \n", print);
	printf("test rp %%.6s -----------> %.6s| \n", print);
	ft_printf("test mp %%.6s -----------> %.6s| \n", print);
	printf("test rp %%.2s -----------> %.2s|\n", print);
	ft_printf("test mp %%.2s -----------> %.2s|\n", print);
	printf("test rp %%-2s -----------> %-2s| \n", print);
	ft_printf("test mp %%-2s -----------> %-2s| \n", print);
	printf("test rp %%-12s -----------> %-12s| \n", print);
	ft_printf("test mp %%-12s -----------> %-12s| \n", print);
	printf("test rp %%-.2s ----------> %-.2s| \n", print);
	ft_printf("test mp %%-.2s ----------> %-.2s| \n", print);
	printf("test rp %%-.12s ---------> %-.12s| \n", print);
	ft_printf("test mp %%-.12s ---------> %-.12s| \n", print);
	printf("test rp %%-12.2s --------> %-12.2s| \n", print);
	ft_printf("test mp %%-12.2s --------> %-12.2s| \n", print);
	printf("test rp %%10.s ----------> %10.s|\n", print);
	ft_printf("test mp %%10.s ----------> %10.s|\n", print);
	printf("test rp %%10.2s ---------> %10.2s|\n", print);
	ft_printf("test mp %%10.2s ---------> %10.2s|\n", print);
	printf("test rp %%----20.0s -----> %----20.0s|\n", print);
	ft_printf("test mp %%----20.0s -----> %----20.0s|\n", print);
	printf("test rp %%.d ------------> %.d| \n", 0);
	ft_printf("test mp %%.d ------------> %.d| \n", 0);
	printf("test rp %%10d -----------> %10d| \n", num);
	ft_printf("test mp %%10d -----------> %10d| \n", num);
	printf("test rp %%.6d -----------> %.6d|\n", num);
	ft_printf("test mp %%.6d -----------> %.6d|\n", num);
	printf("test rp %%-6d -----------> %-6d|\n", num);
	ft_printf("test mp %%-6d -----------> %-6d|\n", num);
	printf("test rp %%-.6d ----------> %-.6d|\n", num);
	ft_printf("test mp %%-.6d ----------> %-.6d|\n", num);
	printf("test rp %%-.18d ---------> %-.18d|\n", num);
	ft_printf("test mp %%-.18d ---------> %-.18d|\n", num);
	printf("test rp %%010d ----------> %010d|\n", num);
	ft_printf("test mp %%010d ----------> %010d|\n", num);
	printf("test rp %%-010d ---------> %-10d|\n", num);
	ft_printf("test mp %%-010d ---------> %-10d|\n", num);
	printf("test rp %%i hexa---------> %i|\n", ici);
	ft_printf("test mp %%d hexa---------> %d|\n", ici);
	ft_printf("test mp %%i hexa---------> %i|\n", ici);
	ft_printf("test mp %%p -------------> %p|\n", ptr);
	printf("test rp %%p -------------> %p|\n", ptr);
	ft_printf("test mp %%p -------------> %p|\n", ptr);
	printf("test rp %%8p ------------> %8p|\n", ptr);
	ft_printf("test mp %%8p ------------> %8p|\n", ptr);
	printf("test rp %%18p -----------> %18p|\n", ptr);
	ft_printf("test mp %%18p -----------> %18p|\n", ptr);
	printf("test rp %%-8p -----------> %-8p|\n", ptr);
	ft_printf("test mp %%-8p -----------> %-8p|\n", ptr);
	printf("test rp %%-18p ----------> %-18p|\n", ptr);
	ft_printf("test mp %%-18p ----------> %-18p|\n", ptr);
	printf("test rp %%-21p ----------> %-21p|\n", ptr);
	ft_printf("test mp %%-21p ----------> %-21p|\n", ptr);
	ft_printf("test mp %%u -------------> %u|\n", nb_un);
	printf("test rp %%u -------------> %u|\n", nb_un);
	ft_printf("test mp %%u -------------> %u|\n", nb_un);
	printf("test rp %%*s 10 ---------> %*s|\n", 10, print);
	ft_printf("test mp %%*s 10 ---------> %*s|\n", 10, print);
	printf("test rp %%*d 10 ---------> %*s|\n", 10, print);
	ft_printf("test mp %%*d 10 ---------> %*s|\n", 10, print);
	printf("test rp %%*.s 10 --------> %*.s|\n", 10, print);
	ft_printf("test mp %%*.s 10 --------> %*.s|\n", 10, print);
	printf("test rp %%*s var --------> %*s|\n", var, print);
	ft_printf("test mp %%*s var --------> %*s|\n", var, print);
	printf("test rp %%d %%*s var+15 -> %d, %*s|\n", var, 15, print);
	ft_printf("test mp %%d %%*s var+15 -> %d, %*s|\n", var, 15, print);
	*/
}

