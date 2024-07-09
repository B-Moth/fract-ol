/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_misc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 16:57:18 by lberne            #+#    #+#             */
/*   Updated: 2024/06/21 18:54:41 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	printchar(int c)
{
	ft_putchar_fd(c, 1);
	return (1);
}

int	printstr(char *str)
{
	if (!str)
	{
		ft_putstr_fd("(null)", 1);
		return (6);
	}
	ft_putstr_fd(str, 1);
	return (ft_strlen(str));
}

int	printint(int n)
{
	char	*nb;
	int		len;

	nb = ft_itoa(n);
	len = printstr(nb);
	free(nb);
	return (len);
}

int	printpercent(void)
{
	ft_putchar_fd('%', 1);
	return (1);
}
