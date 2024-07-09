/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ato_float.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 15:58:04 by lberne            #+#    #+#             */
/*   Updated: 2024/07/04 15:58:20 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double	ft_ato_float(char	*str)
{
	long	int_part;
	double	fractional_part;
	double	power;
	int		sign;

	int_part = 0;
	fractional_part = 0;
	sign = 1;
	power = 1;
	while ((*str >= 9 && *str <= 13) || 32 == *str)
		++str;
	while ('+' == *str || '-' == *str)
		if ('-' == *str++)
			sign = -1;
	while (*str != '.' && *str)
		int_part = (int_part * 10) + (*str++ - 48);
	if ('.' == *str)
		++str;
	while (*str)
	{
		power /= 10;
		fractional_part = fractional_part + (*str++ - 48) * power;
	}
	return ((int_part + fractional_part) * sign);
}