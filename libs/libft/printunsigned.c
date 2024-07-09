/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printunsigned.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/05 14:59:00 by lberne            #+#    #+#             */
/*   Updated: 2024/06/21 18:55:05 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	unsignedlen(unsigned int nb)
{
	int	len;

	len = 0;
	while (nb != 0)
	{
		len++;
		nb = nb / 10;
	}
	return (len);
}

char	*unsigned_itoa(unsigned int n)
{
	int		len;
	char	*nb;

	len = unsignedlen(n);
	nb = (char *)malloc(sizeof(char) * (len + 1));
	if (!nb)
		return (0);
	nb[len] = '\0';
	while (n != 0)
	{
		nb[len - 1] = n % 10 + '0';
		n = n / 10;
		len--;
	}
	return (nb);
}

int	printunsigned(unsigned int n)
{
	int		print_len;
	char	*nb;

	print_len = 0;
	if (n == 0)
		print_len += write(1, "0", 1);
	else
	{
		nb = unsigned_itoa(n);
		print_len += printstr(nb);
		free(nb);
	}
	return (print_len);
}
