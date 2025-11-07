/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/06 13:08:18 by omawele           #+#    #+#             */
/*   Updated: 2025/11/06 13:28:47 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <limits.h>

int	check_size(size_t n, size_t s)
{
	unsigned long	max;
	unsigned long	min;

	max = INT_MAX;
	min = INT_MIN;
	if (n == max || n == min || n < 0)
		return (1);
	else if (s == max || s == min || s < 0)
		return (1);
	return (0);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*tab;
	unsigned int	n;
	unsigned int	fsize;

	if (nmemb == 0 || size == 0)
	{
		tab = malloc(1);
		return ((void *)tab);
	}
	if (check_size(nmemb, size) == 1)
		return (0);
	fsize = nmemb * size;
	tab = malloc(fsize);
	if (tab == 0)
		return ((void *)tab);
	n = 0;
	while (n < fsize)
	{
		tab[n] = 0;
		n++;
	}
	return ((void *) tab);
}
