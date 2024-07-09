/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 17:56:50 by lberne            #+#    #+#             */
/*   Updated: 2024/06/17 15:17:36 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	absolute(int n)
{
	if (n < 0)
		n = n * -1;
	return (n);
}

size_t	len(int n)
{
	size_t	size;

	size = 1;
	if (n == -2147483648)
		return (10);
	n = absolute(n);
	while (n >= 10)
	{
		size++;
		n = n / 10;
	}
	return (size);
}

static void	reverse(char *str)
{
	int			i;
	int			j;
	char		t;

	i = 0;
	j = ft_strlen(str) - 1;
	while (i < j)
	{
		t = str[i];
		str[i] = str[j];
		str[j] = t;
		i++;
		j--;
	}
}

char	*ft_itoa(int n)
{
	int		is_neg;
	int		i;
	char	*res;

	is_neg = 0;
	i = 0;
	if (n < 0)
		is_neg = 1;
	res = ft_calloc(len(n) + 1 + is_neg, sizeof(*res));
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = 0 + 48;
	while (n != 0)
	{
		res[i] = absolute(n % 10) + 48;
		n = n / 10;
		i++;
	}
	if (is_neg)
		res[i] = '-';
	reverse(res);
	return (res);
}
/*
#include <stdio.h>
size_t	ft_strlen(const char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*pointer;

	pointer = (void *)malloc(count * size);
	if (!pointer)
		return (NULL);
	ft_bzero(pointer, count);
	return (pointer);
}

void	ft_bzero(void *s, size_t n)
{
	unsigned int	i;

	i = 0;
	if (!s)
		return ;
	while (i < n)
	{
		*(char *)(s + i) = 0;
		i++;
	}
}

int	main(int ac, char **av)
{
	int	nb = atoi(av[1]);
	char	*res = ft_itoa(nb);
	ac = 0;
	printf("%s\n", res);

	return (0);
}
*/
