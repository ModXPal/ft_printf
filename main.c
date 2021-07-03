/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:16:55 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/03 11:00:29 by rcollas          ###   ########.fr       */
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
	/*
	printf("test rp %%010.2d --> |%010.2d| \n", 5);
	ft_printf("test mp %%010.2d --> |%010.2d| \n", 5);
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
	printf("test rp %%.3s -----------> |%.3s|\n", NULL);
	ft_printf("test mp %%.3s -----------> |%.3s|\n", NULL);
	printf("test rp %%4.3s ----------> |%4.3s|\n", print);
	ft_printf("test mp %%4.3s ----------> |%4.3s|\n", print);
	*/
	printf("test rp %%d ------------> |%d| \n", 0);
	ft_printf("test mp %%d ------------> |%d| \n", 0);
	printf("test rp %%.d ------------> |%.d| \n", 0);
	ft_printf("test mp %%.d ------------> |%.d| \n", 0);
	printf("test rp %%.0d -----------> |%.0d| \n", 0);
	ft_printf("test mp %%.0d -----------> |%.0d| \n", 0);
	printf("test rp %%-.2d -----------> |%-.2d| \n", 0);
	ft_printf("test mp %%-.2d -----------> |%-.2d| \n", 0);
	printf("test rp %%-3.2d -----------> |%-3.2d| \n", 1);
	ft_printf("test rp %%-3.2d -----------> |%-3.2d| \n", 1);
	printf("test rp %%-2.2d -----------> |%-2.2d| \n", 0);
	ft_printf("test mp %%-2.2d -----------> |%-2.2d| \n", 0);
	printf("test rp %%-3.0d -----------> |%-3.0d| \n", 0);
	ft_printf("test mp %%-3.0d -----------> |%-3.0d| \n", 0);
	printf("test rp %%10d -----------> |%10d| \n", num);
	ft_printf("test mp %%10d -----------> |%10d| \n", num);
	printf("test rp %%.6d -----------> |%.6d|\n", num);
	ft_printf("test mp %%.6d -----------> |%.6d|\n", num);
	printf("test rp %%-6d -----------> |%-6d|\n", num);
	ft_printf("test mp %%-6d -----------> |%-6d|\n", num);
	printf("test rp %%-.2d ----------> |%-.2d|\n", 0);
	ft_printf("test mp %%-.2d ----------> |%-.2d|\n", 0);
	printf("test rp %%-3.2d ---------> |%-3.2d|\n", 0);
	ft_printf("test mp %%-3.2d ---------> |%-3.2d|\n", 0);
	printf("test rp %%010d ----------> |%010d|\n", num);
	ft_printf("test mp %%010d ----------> |%010d|\n", num);
	printf("test rp %%-010d ---------> |%-10d|\n", num);
	ft_printf("test mp %%-010d ---------> |%-10d|\n", num);
	printf("test rp %%10.42d 0-------> |%10.42d|\n", 0);
	ft_printf("test mp %%10.42d 0-------> |%10.42d|\n", 0);
	printf("test rp %%10.42d -1 -----> |%10.42d|\n", -1);
	ft_printf("test mp %%10.42d -1 -----> |%10.42d|\n", -1);
	printf("test rp %%-3.2d -1 -----> |%-3.2d|\n", -1);
	ft_printf("test mp %%-3.2d -1 -----> |%-3.2d|\n", -1);
	printf("test rp %%-6.5d -123 -----> |%-6.5d|\n", -123);
	ft_printf("test mp %%-6.5d -123 -----> |%-6.5d|\n", -123);
	printf("test rp %%-3.2d 1---------> |%-3.2d| \n", 1);
	ft_printf("test mp %%-3.2d 1---------> |%-3.2d| \n", 1);
	printf("test rp *%%-*.*d* *%%*.*d*-> |*%-*.*d* *%*.*d*| \n", 6, 2, 102, 10, 21, -101);
	ft_printf("test mp *%%-*.*d* *%%*.*d*-> |*%-*.*d* *%*.*d*| \n", 6, 2, 102, 10, 21, -101);
	printf("test rp 0*%%0-*.*d*0 0*%%0*.*d*0 -> |0*%0-*.*d*0 0*%0*.*d*0| \n" , 6, 2, 102, 10, 21, -101);
	ft_printf("test mp 0*%%0-*.*d*0 0*%%0*.*d*0 -> |0*%0-*.*d*0 0*%0*.*d*0| \n" , 6, 2, 102, 10, 21, -101);
	printf("test rp 0*%%0-*.*d*0 0*%%0*.*d*0 -> |0*%0-*.*d*0 0*%0*.*d*0| \n" , 2, 6, 102, 21, 10, -101);
	ft_printf("test mp 0*%%0-*.*d*0 0*%%0*.*d*0 -> |0*%0-*.*d*0 0*%0*.*d*0| \n" , 2, 6, 102, 21, 10, -101);
	printf("test rp 0*%%0-*d*0 0*%%0*d*0 -----> |0*%0-*d*0 0*%0*d*0| \n", 21, 1021, 21, -1011);
	ft_printf("test mp 0*%%0-*d*0 0*%%0*d*0 -----> |0*%0-*d*0 0*%0*d*0| \n", 21, 1021, 21, -1011);
	printf("test rp 0*%%-0*.10d*0 0*%%-0*.0d*0 -> |0*%-0*.10d*0 0*%-0*.0d*0| \n", 21, 1021, 21, -1011);
	ft_printf("test mp 0*%%-0*.10d*0 0*%%-0*.0d*0 -> |0*%-0*.10d*0 0*%-0*.0d*0| \n", 21, 1021, 21, -1011);
	printf("test rp %%-*.*d ----------> |%-*.*d| \n", 6, 2, 123);
	ft_printf("test mp %%-*.*d ----------> |%-*.*d| \n", 6, 2, 123);
	printf("test rp de Vincent --0*%%0*.0d*0 0*%%0*.10d*0-- -> |--0*%0*.0d*0 0*%0*.10d*0--| \n", -2, 0, 21, 1);
	ft_printf("test mp de Vincent --0*%%0*.0d*0 0*%%0*.10d*0-- -> |--0*%0*.0d*0 0*%0*.10d*0--| \n", -2, 0, 21, 1);
	printf("test rp --0*%%0*.0d*0 0*%%0*.10d*0-- -> |--0*%0*.0d*0 0*%0*.10d*0--| \n", -21, 2147483647, 21, -2147483648);
	ft_printf("test mp --0*%%0*.0d*0 0*%%0*.10d*0-- -> |--0*%0*.0d*0 0*%0*.10d*0--| \n", -21, 2147483647, 21, -2147483648);
	printf("test rp UINT_MAX %%10.0d -> |%10.0d| \n", 4294967295); 
	ft_printf("test mp UINT_MAX %%10.0d -> |%10.0d| \n", 4294967295); 
	printf("test rp UINT_MAX+1 %%09.2d -> |%09.2d| \n", 4294967295 + 1); 
	ft_printf("test mp UINT_MAX+1 %%09.2d -> |%09.2d| \n", 4294967295 + 1); 
	printf("test rp UINT_MAX+1 %%09.0d -> |%09.0d| \n", 4294967295 + 1); 
	ft_printf("test mp UINT_MAX+1 %%09.0d -> |%09.0d| \n", 4294967295 + 1); 
	printf("test rp CHAR_MAX CHAR_MIN --0*%%-0*.2d*0 0*%%-0*.2d*0-- --> |--0*%-0*.2d*0 0*%-0*.2d*0--| \n", -21, 127, 21, -128); 
	ft_printf("test mp CHAR_MAX CHAR_MIN --0*%%-0*.2d*0 0*%%-0*.2d*0-- --> |--0*%-0*.2d*0 0*%-*d*0--| \n", -21, 127, 21, -128); 
	/*
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
	printf("test rp %%*.3s %%.3s 10 -> |%*.3s||%.3s| \n", 10, "123", "4567");
	ft_printf("test mp %%*.3s %%.3s 10 -> |%*.3s||%.3s| \n", 10, "123", "4567");
	printf("test rp %%.*s -----------> |%.*s|\n", -2, NULL);
	ft_printf("test mp %%.*s -----------> |%.*s|\n", -2, NULL);
	*/
}

