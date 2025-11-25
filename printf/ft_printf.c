/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:24 by omawele           #+#    #+#             */
/*   Updated: 2025/11/25 17:10:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int	ft_nil_null(int mode)
{
	int 	var_len;

	var_len = 0;
	if (mode == 0)
		var_len = write(1, "(nil)", ft_strlen("(nil)"));
	else if (mode == 1)
		var_len = write(1, "(null)", ft_strlen("(null)"));
	return (var_len);
}

int	 ft_convert(char c, va_list *args, int *read_bytes)
{
	int	var_len;

	var_len = 0;
	if (c == 'd' || c == 'i' || c == 'u')
		var_len = ft_convert_int(c, args);
	else if (c == 'c' || c == '%')
		var_len = ft_convert_char(c, args);
	else if (c == 's')
		var_len = ft_convert_string(args);
	else if (c == 'x' || c == 'X')
		var_len = ft_convert_hexa(c, args);
	else if (c == 'p')
		var_len = ft_convert_pointer(args);
	else
	{
		var_len = ft_convert_char('%', args);
		if (c == '\0')
			return (-1);
		if (c == ' ' || (c <= 13 && c >= 9))
			*read_bytes -= 1;
	}
	return (var_len);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		result;
	int 	tmp;
	int		read_bytes;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	read_bytes = -1;
	result = 0;
	tmp = 0;
	while (format[++read_bytes])
	{
		if (format[read_bytes] == '%')
		{
			tmp = ft_convert(format[++read_bytes], &args, &read_bytes);
			if (tmp == -1)
				return (result + 1);
			result += tmp;
			read_bytes++;
		}
		result += write(1, (format + read_bytes), 1);
	}
	va_end(args);
	return (result);
}
