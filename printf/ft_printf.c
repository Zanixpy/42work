/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:24 by omawele           #+#    #+#             */
/*   Updated: 2025/11/26 10:01:16 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include "libft/libft.h"

int	ft_is_format(char c)
{
	const char	*format = "cspdiuxX%";

	if (ft_strchr(format, c))
		return (1);
	return (0);
}

void	ft_print(char c, va_list *args, int *count)
{
	if (c == 'd' || c == 'i')
		ft_print_int((int)va_arg(*args, int), count);
	else if (c == 'u')
		ft_print_int((unsigned int)va_arg(*args, unsigned int), count);
	else if (c == 'c')
		ft_print_char((char)va_arg(*args, int), count);
	else if (c == '%')
		ft_print_char('%', count);
	else if (c == 's')
		ft_print_string((char *)va_arg(*args, char *), count);
	else if (c == 'x' || c == 'X')
		ft_print_hexa((long)va_arg(*args, long), count, c);
	else if (c == 'p')
		ft_print_pointer((void *)va_arg(*args, void *), count);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		count;
	int		read_bytes;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	read_bytes = 0;
	count = 0;
	while (format[read_bytes])
	{
		if (format[read_bytes] == '%' && ft_is_format(format[read_bytes + 1]))
		{
			ft_print(format[read_bytes + 1], &args, &count);
			read_bytes += 2;
		}
		else
		{
			ft_print_char(format[read_bytes], &count);
			read_bytes++;
		}
	}
	va_end(args);
	return (count);
}
