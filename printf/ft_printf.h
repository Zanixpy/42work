/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:40:07 by omawele           #+#    #+#             */
/*   Updated: 2025/11/26 10:01:19 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>

int		ft_printf(const char *format, ...);
void	ft_print(char c, va_list *args, int *count);
int		ft_is_format(char c);
void	ft_print_char(char c, int *count);
void	ft_print_int(long n, int *count);
void	ft_print_hexa(long n, int *count, char mode);
void	ft_print_string(char *s, int *count);
void	ft_print_pointer(void *ptr, int *count);
char	ft_hexa(int pos, char mode);

#endif