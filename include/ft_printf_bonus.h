/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:05:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/20 15:45:48 by rcollas          ###   ########.fr       */
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
	int	precision;
	int	wildcard;
	int	put_zero;
	int	put_space;
	int	count;
}	t_spec;

typedef struct s_flag
{
	char	flag;
	void	(*func)(va_list, t_spec *);
}		t_flag;

typedef struct s_tree
{
	char			flag;
	struct s_tree	*left;
	struct s_tree	*right;
	struct s_flag	*trig;
}	t_tree;

void	ft_putstring(va_list str, t_spec *spec);
void	ft_putnbr(va_list nb, t_spec *spec);
void	ft_putnbr_unsigned(va_list nb, t_spec *spec);
void	ft_putnbr_upbase(va_list nb, t_spec *spec);
void	ft_putnbr_lobase(va_list nb, t_spec *spec);
void	ft_put_ptr(va_list nb, t_spec *spec);
void	ft_putchar(va_list c, t_spec *spec);
void	ft_put_percent(va_list nul, t_spec *spec);
int	get_str_len(t_spec *spec, char *str);
int		ft_putnchar(char c, int len);
int		ft_strlen(char *str);
int		ft_nblen(int nb);
int		ft_unblen(unsigned int nb);
int		ft_nblenbase(unsigned long int nb);
int		ft_printf(const char *str, ...);
int		ft_isdigit(char c);
int		ft_atoi(const char **);
int		ft_putstr(char *str);

#endif
