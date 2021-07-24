/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 16:05:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 20:18:50 by rcollas          ###   ########.fr       */
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

void	ft_putstring(va_list str, t_spec *spec);
void	ft_putnbr(va_list nb, t_spec *spec);
void	ft_putnbr_unsigned(va_list nb, t_spec *spec);
void	ft_putnbr_upbase(va_list nb, t_spec *spec);
void	ft_putnbr_lobase(va_list nb, t_spec *spec);
void	ft_put_ptr(va_list nb, t_spec *spec);
void	ft_putchar(va_list c, t_spec *spec);
void	ft_put_percent(va_list perc, t_spec *spec);
void	ft_print_flag(t_flag func[9], char flag, va_list arg, t_spec *spec);
void	parser(t_spec *spec, va_list arguments, const char **str);
void	init_flag(t_flag to_init[9]);
void	get_str_len(t_spec *spec, char *str);
void	negative_width_precision(t_spec *spec);
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
