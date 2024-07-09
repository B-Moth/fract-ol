/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 13:18:48 by lberne            #+#    #+#             */
/*   Updated: 2024/06/17 15:15:42 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_size;
	size_t	src_size;
	size_t	i;
	size_t	j;

	if ((!dest && !src) || (!dest && !size))
		return (0);
	dest_size = ft_strlen(dest);
	src_size = ft_strlen(src);
	i = 0;
	j = dest_size;
	if (dest_size < size - 1 && size > 0)
	{
		while (src[i] && dest_size + i < size - 1)
		{
			dest[j] = src[i];
			i++;
			j++;
		}
		dest[j] = 0;
	}
	if (dest_size >= size)
		dest_size = size;
	return (dest_size + src_size);
}
