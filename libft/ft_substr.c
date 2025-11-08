/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:43:37 by omawele           #+#    #+#             */
/*   Updated: 2025/11/08 11:47:24 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_len(char const *s)
{
	unsigned int	n;

	n = 0;
	while (*s)
	{
		n++;
		s++;
	}
	return (n);
}

static char	*empty(void)
{
	char	*tmp;

	tmp = malloc(sizeof(char));
	if (tmp == 0)
		return (0);
	tmp[0] = '\0';
	return (tmp);
}

static int	check(char const *s, unsigned int start, size_t len)
{
	if (start > len || start > ft_len(s))
		return (1);
	if (start == 0 && len == 0)
		return (1);
	if (len > ft_len(s))
		return (2);
	if (start == len || (len - start == 1 && s[len] == '\0'))
		return (3);
	if (len - start == 1)
		return (4);
	return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	unsigned int	size;
	char			*tmp;

	if (check(s, start, len) == 1)
		return (empty());
	if (check(s, start, len) == 2)
		len = ft_len(s);
	if (check(s, start, len) == 3)
		size = 1;
	else if (check(s, start, len) == 4)
		size = 2;
	else
		size = len - start;
	tmp = malloc((size + 1) * sizeof(char));
	if (tmp == 0)
		return (0);
	n = 0;
	while (n < size)
	{
		tmp[n] = s[start++];
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}
