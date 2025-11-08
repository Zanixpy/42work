/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 17:14:13 by omawele           #+#    #+#             */
/*   Updated: 2025/11/07 17:21:33 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

/*static size_t	ft_len(const char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}*/

static void increment(const char **big, size_t *i)
{
	const char *str;
	size_t j;

	str = *big;
	j = *i;
	str++;
	j++;
	*big = str;
	*i = j;
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	if (*little == '\0')
		return ((char *) big);
	i = 0;
	while (*big && i < len)
	{
		j = 0;
		if (*big == little[j] && i < len)
		{
			while (*big == little[j] && i < len)
			{
				j++;
				i++;
				big++;
				if (little[j] == '\0')
					return ((char *)(big - (j - 1)));	
			}
		}
		else
			increment(&big, &i);
	}
	if (*big == 0)
	{
		printf("Avant le nul %s\n", big - 1);		
	}
	return (0);
}
