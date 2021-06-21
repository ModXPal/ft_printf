/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:05:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/18 18:00:52 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef struct s_flag
{
	char	flag;
	int		(*func)(va_list);
}		t_flag;

typedef struct s_tree
{
	char			flag;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_flag	*trig;
}	t_tree;

int	ft_putstr(va_list str);
int	ft_putnbr(va_list nb);
int	ft_putnbr_unsigned(va_list nb);
int	ft_putnbr_upbase(va_list nb);
int	ft_putnbr_lobase(va_list nb);
int	ft_put_ptr(va_list nb);
int	ft_putchar(va_list c);
int	ft_put_percent(va_list nul);

#endif
