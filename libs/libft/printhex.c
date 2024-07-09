/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printhex.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 12:59:06 by lberne            #+#    #+#             */
/*   Updated: 2024/06/21 18:54:54 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	puthex(unsigned int nb, const char format)
{
	if (nb >= 16)
	{
		puthex(nb / 16, format);
		puthex(nb % 16, format);
	}
	else
	{
		if (nb <= 9)
			ft_putchar_fd((nb + '0'), 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((nb - 10 + 'a'), 1);
			else if (format == 'X')
				ft_putchar_fd((nb - 10 + 'A'), 1);
		}
	}
}

int	hexlen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 16;
	}
	return (len);
}

int	printhex(unsigned int nb, const char format)
{
	if (nb == 0)
	{
		ft_putchar_fd('0', 1);
		return (1);
	}
	else
		puthex(nb, format);
	return (hexlen(nb));
}
