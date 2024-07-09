/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lucas <lucas@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/04 15:26:42 by lberne            #+#    #+#             */
/*   Updated: 2024/06/24 16:32:01 by lucas            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	print_format(va_list args, const char format)
{
	int	length;

	length = 0;
	if (format == 'c')
		length += printchar(va_arg(args, int));
	else if (format == 's')
		length += printstr(va_arg(args, char *));
	else if (format == 'p')
		length += printptr(va_arg(args, void *));
	else if (format == 'd' || format == 'i')
		length += printint(va_arg(args, int));
	else if (format == 'u')
		length += printunsigned(va_arg(args, unsigned int));
	else if (format == 'x' || format == 'X')
		length += printhex(va_arg(args, unsigned int), format);
	else if (format == '%')
		length += printpercent();
	return (length);
}

int	ft_printf(const char *str, ...)
{
	int		i;
	int		total_length;
	va_list	args;

	i = 0;
	total_length = 0;
	va_start(args, str);
	while (str[i])
	{
		if (str[i] == '%')
		{
			total_length += print_format(args, str[i + 1]);
			i++;
		}
		else
			total_length += printchar(str[i]);
		i++;
	}
	va_end(args);
	return (total_length);
}
