/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:30:41 by lberne            #+#    #+#             */
/*   Updated: 2024/06/17 15:15:45 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*res;
	size_t	i;

	i = 0;
	if (!s)
		return (NULL);
	res = ft_strdup(s);
	if (!res)
		return (NULL);
	while (res[i])
	{
		res[i] = (*f)(i, res[i]);
		i++;
	}
	return (res);
}
