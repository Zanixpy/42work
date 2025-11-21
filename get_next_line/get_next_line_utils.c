/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:20:42 by omawele           #+#    #+#             */
/*   Updated: 2025/11/21 14:46:34 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t	n;

	n = 0;
	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	char	src;

	src = c;
	while (*s)
	{
		if (*s == src)
			return ((char *)s);
		s++;
	}
	if (*s == src)
		return ((char *)s);
	return (NULL);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	n;
	char			*tmp;
	size_t			fsize;
	size_t			ssize;

	fsize = ft_strlen(s1);
	ssize = ft_strlen(s2);
	tmp = malloc((fsize + ssize + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	n = 0;
	while (*s1)
	{
		tmp[n] = *s1;
		s1++;
		n++;
	}
	while (*s2)
	{
		tmp[n] = *s2;
		s2++;
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		n;

	n = 0;
	while (s[n])
		n++;
	cp = malloc(sizeof(char) * (n + 1));
	if (cp == NULL)
		return (NULL);
	n = 0;
	while (s[n])
	{
		cp[n] = s[n];
		n++;
	}
	cp[n] = '\0';
	return (cp);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	char			*tmp;

	if ((start == 0 && len == 0) || start >= ft_strlen(s))
	{
		tmp = malloc(sizeof(char));
		if (tmp == NULL)
			return (NULL);
		tmp[0] = '\0';
		return (tmp);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	tmp = malloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	n = 0;
	while (s[start] && n < len)
	{
		tmp[n] = s[start];
		n++;
		start++;
	}
	tmp[n] = '\0';
	return (tmp);
}
