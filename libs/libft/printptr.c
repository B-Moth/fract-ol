/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printptr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 18:01:49 by nnuno-ca          #+#    #+#             */
/*   Updated: 2024/06/21 18:55:01 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	p_digits(unsigned long long n)
{
	size_t	digits;

	digits = 0;
	if (n == 0)
		return (1);
	while (n != 0)
	{
		digits += 1;
		n /= 16;
	}
	return (digits);
}

static void	putptr(unsigned long long addr)
{
	static char	digits[] = "0123456789abcdef";

	if (addr >= 16)
		putptr(addr / 16);
	write(1, &digits[addr % 16], 1);
}

int	printptr(void *addr)
{
	if (addr == NULL)
		return (write(1, "(nil)", 5));
	write(1, "0x", 2);
	putptr((unsigned long long)addr);
	return (p_digits((unsigned long long)addr) + 2);
}
