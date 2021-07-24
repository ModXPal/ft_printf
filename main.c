/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/22 16:16:55 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 19:53:53 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "include/ft_printf.h"
# define UINT_MAX 4294967295
#define INT_MAX 2147483647
#define INT_MIN -2147483648
#define CHAR_MAX 127
# define CHAR_MIN -128

int	main(void)
{
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
	printf("test rp %%-12s -----------> %-12s| \n", print)10d| \n", num);
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
	printf("test rp %%-3.2u %%10.42u 1 -1 ----> |%-3.2u %10.42u| \n", 1, -1);
	ft_printf("test mp %%-3.2u %%10.42u 1 -1 ----> |%-3.2u %10.42u| \n", 1, -1);
	printf("test rp UINT_MAX %%9.0u ----------> |%9.0u| \n", 4294967295);
	ft_printf("test mp UINT_MAX %%9.0u ----------> |%9.0u| \n", 4294967295);
	printf("test rp %%*c%%*c ---------> |%*c%*c| \n", -10, '0', 10, '1');
	ft_printf("test mp %%*c%%*c ---------> |%*c%*c| \n", -10, '0', 10, '1');
	printf("test rp %%x 0 ----> |%x| \n", 0);
	ft_printf("test mp %%x 0 ----> |%x| \n", 0);
	printf("test rp %%x -1 ----> |%x| \n", -1);
	ft_printf("test mp %%x -1 ----> |%x| \n", -1);
	printf("test rp %%x -10 ----> |%x| \n", -10);
	ft_printf("test mp %%x -10 ----> |%x| \n", -10);
	printf("test rp %%p %%p LONG_MIN LONG_MAX ----> |%p %p| \n", -2147483648, 2147483647);
	ft_printf("test mp %%p %%p LONG_MIN LONG_MAX ----> |%p %p| \n", -2147483648, 2147483647);
	printf("test rp %%p %%p 0 0 -----> |%p %p| \n", 0, 0);
	ft_printf("test mp %%p %%p 0 0 -----> |%p %p| \n", 0, 0);
	printf("retour rp = %d ||| \n", printf("test rp %%p %%p 0 0 -----> |%p %p| \n", NULL, NULL));
	ft_printf("retour mp = %d ||| \n", ft_printf("test mp %%p %%p 0 0 -----> |%p %p| \n", NULL, NULL));
	printf("test rp %%-2p -1 ---> |%-2p| \n", -1);
	ft_printf("test mp %%-2p -1 ---> |%-2p| \n", -1);
	printf("retour rp = %d ||| \n", printf("test rp %%-3p 16 ---> |%-3p| \n", 16));
	ft_printf("retour mp = %d ||| \n", ft_printf("test mp %%-3p 16 ---> |%-3p| \n", 16));
	printf("test rp %%-9p %%-10p LONG_MIN_MAX ---> |%-9p %-10p| \n", -9223372036854775808, 9223372036854775807);
	ft_printf("test mp %%-9p %%-10p LONG_MIN_MAX ---> |%-9p %-10p| \n", -9223372036854775808, 9223372036854775807);
	printf("retour rp = %d \n", printf("test rp %%-15x LONG_MAX ---> |%-15x| \n", 9223372036854775807LL));
	printf("retour mp = %d \n", ft_printf("test mp %%-15x LONG_MAX ---> |%-15x| \n", 9223372036854775807LL));
	printf("test rp %%4.3x ----> |%*.*x| \n", 4, 3, 0);
	ft_printf("test mp %%4.3x ----> |%*.*x| \n", 4, 3, 0);
	printf("test rp %%-4.0x ---> |%*.*x| \n", -4, 0, 0);
	ft_printf("test mp %%-4.0x ---> |%*.*x| \n", -4, 0, 0);
	printf("test rp %%-1.0x ---> |%*.*x| \n", -1, 0, 0);
	ft_printf("test mp %%-1.0x ---> |%*.*x| \n", -1, 0, 0);
	printf("test rp %%-4.c ---> |%-4.c| \n", 'y');
	ft_printf("test mp %%-4.c ---> |%-4.c| \n", 'y');
	printf("test rp %%-1.c ---> |%-1.c| \n", 'y');
	ft_printf("test mp %%-1.c ---> |%-1.c| \n", 'y');
	printf("test rp %%-16.p ---> |%-16.p| \n", 0);
	ft_printf("test mp %%-16.p ---> |%-16.p| \n", 0);
	printf("test rp %%02.%% ---> |%02.%| \n");
	ft_printf("test mp %%02.%% ---> |%02.%| \n");
	printf("test rp %%02.-4%% ---> |%0*.*%| \n", 2, -4);
	ft_printf("test mp %%02.-4%% ---> |%0*.*%| \n", 2, -4);
//	printf("retour rp = %d \n", printf("test rp %%-15x LONG_MAX ---> |%-15x| \n", 2147483647));
//	printf("retour mp = %d \n", ft_printf("test mp %%-15x LONG_MAX ---> |%-15x| \n", 2147483647));
//	ft_printf("%0i, %0d, %0d, %0d, %0d, %0d, %0d, %0d", 8, -12, 123456789, 0, -12345678, 'a', -2147483748, 2147483647);
//	ft_printf("%0d \n", 0);
	printf("test rp CHAR_MAX CHAR_MIN --0*%%-0*.2d*0 0*%%-0*.2d*0-- --> |--0*%-0*.2d*0 0*%-0*.2d*0--| \n", -21, 127, 21, -128); 
	ft_printf("test mp CHAR_MAX CHAR_MIN --0*%%-0*.2d*0 0*%%-0*.2d*0-- --> |--0*%-0*.2d*0 0*%-0*.2d*0--| \n", -21, 127, 21, -128); 
	printf("test rp 0*%%0-*d*0 0*%%0*d*0 ----> |0*%0-*d*0 0*%0*d*0| \n", 21, 1021, 21, -1011);
	ft_printf("test mp 0*%%0-*d*0 0*%%0*d*0 ----> |0*%0-*d*0 0*%0*d*0| \n", 21, 1021, 21, -1011);
	printf("test rp UINT_MAX %%10.10d -------> |%10.10d| \n", 4294967295);
	ft_printf("test mp UINT_MAX %%10.10d -------> |%10.10d| \n", 4294967295);
	printf("test rp %%3d 0 ------------------> |%3d| \n", 0);
	ft_printf("test mp %%3d 0 ------------------> |%3d| \n", 0);
	printf("test rp %%0*d -7 -54 ------------> |%0*d| \n", -7, -54);
	ft_printf("test mp %%0*d -7 -54 ------------> |%0*d| \n", -7, -54);
	printf("test rp %%03d 0 -----------------> |%03d| \n", 0);
	ft_printf("test mp %%03d 0 -----------------> |%03d| \n", 0);
	printf("test rp %%3d 0 -----------------> |%3d| \n", 0);
	ft_printf("test mp %%3d 0 -----------------> |%3d| \n", 0);
	printf("test rp %%1.1d ------------------> |%1.1d| \n", 0);
	ft_printf("test rp %%1.1d ------------------> |%1.1d| \n", 0);
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
	printf("test rp %%   *.6i ---> |%   *.6i| \n", 2, 42);
	ft_printf("test mp %%   *.6i ---> |%   *.6i| \n", 2, 42);
	printf("%");
	ft_printf("%");
	printf("test rp %%09s ---> |%09s| \n", "test");
	ft_printf("test mp %%09s ---> |%09s| \n", "test");
	*/
	printf("test rp %%2.9p ---> |%2.9p| \n", 1234);
	ft_printf("test mp %%2.9p ---> |%2.9p| \n", 1234);
}

