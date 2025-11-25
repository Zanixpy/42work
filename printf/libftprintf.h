/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:40:07 by omawele           #+#    #+#             */
/*   Updated: 2025/11/25 11:46:17 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
int	 ft_convert(char c, va_list *args, int *read_bytes);
int	 ft_convert_int(char c, va_list *args);
int ft_convert_char(char c, va_list *args);
int ft_convert_string(va_list *args);
int ft_convert_hexa(char c, va_list *args);
int ft_convert_pointer(va_list *args);
int	ft_nil_null(int mode);
char	*ft_decimal_to_hexa(unsigned long var, char mode);
char	*ft_strreverse(const char *s);
char	ft_hexa(int pos, char mode);
char	*ft_pointer_to_hexa(unsigned long var);
char	*ft_check_unsigned_int(long var);
int		ft_str_is_null(char *str, int n, ...);
char	*ft_create_string_hexa(char **var_convert, char **tmp);
char	*ft_itoa_long(long n);

#endif