/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:05:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/06/22 19:08:41 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdio.h>

typedef	struct s_spec
{
	int width;
	int dot;
	int dash;
	int	zero;
	int	before_dot;
	int after_dot;
	int	precision;
	int	wildcard;
}	t_spec;

typedef struct s_flag
{
	char	flag;
	int		(*func)(va_list, t_spec *);
}		t_flag;

typedef struct s_tree
{
	char			flag;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_flag	*trig;
}	t_tree;

int	ft_putstr(va_list str, t_spec *specifers);
int	ft_putnbr(va_list nb, t_spec *specifers);
int	ft_putnbr_unsigned(va_list nb, t_spec *specifers);
int	ft_putnbr_upbase(va_list nb, t_spec *specifers);
int	ft_putnbr_lobase(va_list nb, t_spec *specifers);
int	ft_put_ptr(va_list nb, t_spec *specifers);
int	ft_putchar(va_list c, t_spec *specifers);
int	ft_put_percent(va_list nul, t_spec *specifers);
int	ft_strlen(char *str);
int	ft_nblen(int nb);
int	ft_putnchar(char c, int len);
int	ft_nblenbase(long nb);
int	ft_printf(const char *str, ...);

#endif
