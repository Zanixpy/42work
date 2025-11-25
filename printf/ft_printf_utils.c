/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 13:39:29 by omawele           #+#    #+#             */
/*   Updated: 2025/11/25 11:46:09 by omawele          ###   ########.fr       */
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
