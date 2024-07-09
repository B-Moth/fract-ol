/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 18:23:26 by lberne            #+#    #+#             */
/*   Updated: 2024/06/17 15:15:48 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	is_set(char c, char const *set)
{
	int	i;

	i = 0;
	while (set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res;
	int		beginning;
	int		ending;
	int		i;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	beginning = 0;
	ending = ft_strlen(s1);
	while (s1[beginning] && is_set(s1[beginning], set))
		beginning++;
	while (ending > beginning && is_set(s1[ending - 1], set))
		ending--;
	res = (char *)malloc(sizeof(*s1) * (ending - beginning + 1));
	if (!res)
		return (NULL);
	while (beginning < ending)
		res[i++] = s1[beginning++];
	res[i] = 0;
	return (res);
}
