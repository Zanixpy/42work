/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_type.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:19 by omawele           #+#    #+#             */
/*   Updated: 2025/11/25 11:46:34 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

int	 ft_convert_int(char c, va_list *args)
{
	int		var_int;
	char	*var_convert;
	long	var_unsigned_int;
	int		var_len;

	var_len = 0;
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
		return (-1);
	var_len = write(1, var_convert, ft_strlen(var_convert));
	free(var_convert);
	return (var_len);
}

int ft_convert_char(char c, va_list *args)
{
	char	var_char;
	int 	var_len;

	if (c == '%')
		var_len = write(1, &c, 1);
	else
	{
		var_char = va_arg(*args, int);
		var_len = write(1, &var_char, 1);
	}
	return (var_len);
}

int ft_convert_string(va_list *args)
{
	char	*var_string;
	int		var_len;

	var_string = va_arg(*args, char *);
	if (var_string == NULL)
		return (ft_nil_null(1));
	var_len = write(1, var_string, ft_strlen(var_string));
	return (var_len);
}

int ft_convert_hexa(char c, va_list *args)
{
	unsigned int	var_int;
	char			*var_convert;
	int 		var_len;

	var_int = va_arg(*args, int);
	var_convert = ft_decimal_to_hexa(var_int, c);
	if (var_convert == NULL)
		return (-1);
	var_len = write(1, var_convert, ft_strlen(var_convert));
	free(var_convert);
	return (var_len);
}

int ft_convert_pointer(va_list *args)
{
	char		*var_convert;
	void		*var_pointer;
	uintptr_t	ptr;
	char		*var_hexa;
	char		*tmp;

	var_pointer = va_arg(*args, void *);
	if (var_pointer == NULL)
		return (ft_nil_null(0));
	ptr = (uintptr_t)var_pointer;
	var_convert = ft_decimal_to_hexa(ptr, 'x');
	if (var_convert == NULL)
		return (-1);
	tmp = "0x";
	var_hexa = var_convert;
	var_convert = ft_strjoin(tmp, var_hexa);
	free(var_hexa);
	if (var_convert == NULL)
		return (-1);
	ptr = write(1, var_convert, ft_strlen(var_convert));
	free(var_convert);
	return (ptr);
}
