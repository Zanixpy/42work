/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:19 by omawele           #+#    #+#             */
/*   Updated: 2025/11/19 15:08:03 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

char	*ft_convert_int(char c, va_list *args)
{
	int		var_int;
	char	*var_convert;
	long	var_unsigned_int;

	var_convert = NULL;
	if (c == 'u')
	{
		var_unsigned_int = va_arg(*args, long);
		var_convert = ft_check_unsigned_int(var_unsigned_int);
	}
	else
	{
		var_int = va_arg(*args, int);
		var_convert = ft_itoa(var_int);
	}
	if (var_convert == NULL)
		return (NULL);
	return (var_convert);
}

char	*ft_convert_char(char c, va_list *args)
{
	char	var_char;
	char	*var_convert;

	var_convert = ft_calloc(2, sizeof(char));
	if (var_convert == NULL)
		return (NULL);
	if (c == '%')
		var_convert[0] = '%';
	else
	{
		var_char = va_arg(*args, int);
		var_convert[0] = var_char;
	}
	return (var_convert);
}

char	*ft_convert_string(va_list *args)
{
	char	*var_string;
	char	*var_convert;

	var_string = va_arg(*args, char *);
	var_convert = ft_strdup(var_string);
	if (var_convert == NULL)
		return (NULL);
	return (var_convert);
}

char	*ft_convert_hexa(char c, va_list *args)
{
	unsigned int	var_int;
	char			*var_convert;
	char			*tmp;

	tmp = ft_calloc(1, sizeof(char));
	if (tmp == NULL)
		return (NULL);
	var_int = va_arg(*args, int);
	while (var_int != 0)
	{
		var_convert = ft_calloc(2, sizeof(char));
		if (var_convert == NULL)
			return (NULL);
		var_convert[0] = ft_hexa((var_int % 16), c);
		tmp = ft_create_string_hexa(&tmp, &var_convert);
		if (tmp == NULL)
			return (NULL);
		var_int /= 16;
	}
	var_convert = ft_strreverse(tmp);
	free(tmp);
	if (var_convert == NULL)
		return (NULL);
	return (var_convert);
}

char	*ft_convert_pointer(va_list *args)
{
	char		*var_convert;
	void		*var_pointer;
	uintptr_t	ptr;
	char		*var_hexa;
	char		*tmp;

	var_pointer = va_arg(*args, void *);
	ptr = (uintptr_t)var_pointer;
	var_hexa = ft_pointer_to_hexa(ptr);
	if (var_hexa == NULL)
		return (NULL);
	tmp = ft_calloc(3, sizeof(char));
	if (ft_str_is_null(tmp, 1, &var_hexa))
		return (NULL);
	tmp[0] = '0';
	tmp[1] = 'x';
	var_convert = ft_strjoin(tmp, var_hexa);
	ft_freestr(2, &var_hexa, &tmp);
	if (var_convert == NULL)
		return (NULL);
	return (var_convert);
}
