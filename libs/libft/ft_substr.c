/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:14:38 by lberne            #+#    #+#             */
/*   Updated: 2024/06/17 15:15:49 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	i;
	size_t	j;
	char	*res;

	i = start;
	j = 0;
	if (!s)
		return (NULL);
	res = (char *)malloc(sizeof(*s) * (len + 1));
	if (!res)
		return (NULL);
	while (s[i])
	{
		if (i >= start && j < len)
		{
			res[j] = s[i];
			j++;
		}
		i++;
	}
	if (start > ft_strlen(s))
		res[0] = 0;
	res[j] = 0;
	return (res);
}
