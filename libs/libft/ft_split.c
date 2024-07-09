/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lberne <lberne@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:59:50 by lberne            #+#    #+#             */
/*   Updated: 2024/06/18 15:18:01 by lberne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	*free_res(char **res, size_t nb_allocs)
{
	size_t	i;

	i = 0;
	while (i < nb_allocs)
	{
		free(res[i]);
		i++;
	}
	free(res);
	return (NULL);
}

static char	**alloc_res(char const *s, char c)
{
	size_t	i;
	size_t	size_res;
	char	**res;

	i = 0;
	size_res = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size_res++;
			while (s[i] != c && s[i + 1])
				i++;
		}
		i++;
	}
	res = (char **)malloc(sizeof(s) * (size_res + 2));
	if (!res)
		return (NULL);
	return (res);
}

static char	*get_chunk(char const *s, char c, int starter)
{
	char	*chunk;
	size_t	size_chunk;
	int		i;

	i = starter;
	size_chunk = 0;
	while (s[i] != c && s[i])
	{
		size_chunk++;
		i++;
	}
	chunk = (char *)malloc(sizeof(c) * size_chunk + 1);
	if (!chunk)
		return (NULL);
	i = 0;
	while (s[starter] != c && s[starter])
	{
		chunk[i] = s[starter];
		starter++;
		i++;
	}
	chunk[i] = 0;
	return (chunk);
}

char	**master_spliter(char **res, char const *s, char c)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c && s[i])
			i++;
		if (s[i])
		{
			res[j] = get_chunk(s, c, i);
			if (!res[j])
				return (free_res(res, j), NULL);
			j++;
		}
		while (s[i] != c && s[i])
			i++;
	}
	res[j] = 0;
	return (res);
}

char	**ft_split(char const *s, char c)
{
	char	**res;

	if (!s)
		return (NULL);
	res = alloc_res(s, c);
	if (!res)
		return (NULL);
	res = master_spliter(res, s, c);
	return (res);
}
