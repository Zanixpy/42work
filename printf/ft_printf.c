/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:24 by omawele           #+#    #+#             */
/*   Updated: 2025/11/21 17:42:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

void	ft_freestr(int n, ...)
{
	va_list	args;
	char	**var_to_free;
	int		i;

	i = 0;
	va_start(args, n);
	while (i < n)
	{
		var_to_free = va_arg(args, char **);
		free(*var_to_free);
		i++;
	}
	va_end(args);
}

char	*ft_create_string(char **format, char **var_convert, int *read_format)
{
	char	*tmp;
	char	*format_sub;
	char	*final;
	int		new_position;

	format_sub = ft_substr(*format, 0, *read_format - 1);
	if (format_sub == NULL)
		return (NULL);
	tmp = ft_strjoin(format_sub, *var_convert);
	if (ft_str_is_null(tmp, 1, &format_sub))
		return (NULL);
	new_position = ft_strlen(tmp) - 1;
	ft_freestr(2, &format_sub, var_convert);
	format_sub = ft_substr(*format, *read_format + 1, ft_strlen(*format
				+ *read_format + 1));
	if (ft_str_is_null(format_sub, 1, &tmp))
		return (NULL);
	free(*format);
	final = ft_strjoin(tmp, format_sub);
	ft_freestr(2, &tmp, &format_sub);
	if (final == NULL)
		return (NULL);
	*read_format = new_position;
	return (final);
}

char	*ft_convert(char c, va_list *args)
{
	char	*var_convert;

	var_convert = NULL;
	if (c == 'd' || c == 'i' || c == 'u')
		var_convert = ft_convert_int(c, args);
	else if (c == 'c' || c == '%')
		var_convert = ft_convert_char(c, args);
	else if (c == 's')
		var_convert = ft_convert_string(args);
	else if (c == 'x' || c == 'X')
		var_convert = ft_convert_hexa(c, args);
	else if (c == 'p')
		var_convert = ft_convert_pointer(args);
	if (var_convert == NULL)
		return (NULL);
	return (var_convert);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	char	*var_convert;
	char	*final;
	int		read_format;

	final = ft_strdup(format);
	if (final == NULL)
		return (1);
	va_start(args, format);
	read_format = -1;
	while (final[++read_format])
	{
		if (final[read_format] == '%')
		{
			var_convert = ft_convert(final[++read_format], &args);
			if (var_convert == NULL)
				return (1);
			final = ft_create_string(&final, &var_convert, &read_format);
			if (ft_str_is_null(final, 1, &var_convert))
				return (1);
		}
	}
	ft_display_final(&final);
	va_end(args);
	return (0);
}
