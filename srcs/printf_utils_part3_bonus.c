/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils_part3_bonus.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcollas <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/28 10:47:06 by rcollas           #+#    #+#             */
/*   Updated: 2021/07/22 18:38:56 by rcollas          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf_bonus.h"

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
