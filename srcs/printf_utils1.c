/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/24 16:26:44 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/24 16:32:49 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_strlen(char *str)
{
	int i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_nblen(int nb)
{
	long num;
	int i;

	i = 0;
	num = nb;
	if (num == 0)
		return (0);
	if (num < 0)
	{
		num *= -1;
		i++;
	}
	while (num > 0)
	{
		num /= 10;
		i++;
	}
	return (i);
}

int	ft_unblen(unsigned int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (0);
	while (nb > 0)
	{
		nb /= 10;
		i++;
	}
	return (i);
}

int	ft_nblenbase(unsigned long int nb)
{
	int i;

	i = 0;
	if (nb == 0)
		return (1);
	while (nb > 0)
	{
		nb /= 16;
		i++;
	}
	return (i);
}

int	ft_atoi(const char **nptr)
{
	int						sign;
	unsigned long long int	nb;

	nb = 0;
	sign = 1;
	if (**nptr == '-')
	{
		sign *= -1;
		(*nptr)++;
	}
	else if (**nptr == '+')
		(*nptr)++;
	while (ft_isdigit(**nptr))
	{
		nb = nb * 10 + **nptr - 48;
		(*nptr)++;
	}
	return (nb * sign);
}
