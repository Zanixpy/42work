/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:29 by omawele           #+#    #+#             */
/*   Updated: 2025/11/19 15:13:39 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "libftprintf.h"

static void	ft_isnegative(long *nb, int *sign)
{
	if (*nb < 0)
	{
		*sign = 1;
		*nb *= -1;
	}
	else
		*sign = 0;
}

static void	ft_len(long *n, int *size)
{
	long	nb;
	int		len;

	nb = *n;
	len = *size;
	nb /= 10;
	while (nb != 0)
	{
		nb /= 10;
		len++;
	}
	*n = nb;
	*size = len;
}

char	*ft_itoa_long(long n)
{
	char	*str;
	long	tmp;
	int		size;
	int		sign;

	size = 1;
	tmp = n;
	ft_isnegative(&tmp, &sign);
	ft_len(&n, &size);
	size += sign;
	str = malloc((size + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	str[size] = '\0';
	while (size--)
	{
		str[size] = '0' + (tmp % 10);
		tmp /= 10;
	}
	if (sign == 1)
		str[0] = '-';
	return (str);
}

void	ft_display_final(char **final)
{
	ft_putstr_fd(*final, 1);
	free(*final);
}

int	ft_str_is_null(char *str, int n, ...)
{
	va_list	args;
	char	**var_to_free;
	int		i;

	va_start(args, n);
	i = 0;
	if (str == NULL)
	{
		while (i < n)
		{
			var_to_free = va_arg(args, char **);
			free(*var_to_free);
		}
		return (1);
	}
	va_end(args);
	return (0);
}
