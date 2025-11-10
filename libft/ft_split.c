/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/07 15:47:12 by omawele           #+#    #+#             */
/*   Updated: 2025/11/10 16:28:17 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free(char ***tab, int n)
{
	while (n >= 0)
	{
		free((*tab)[n]);
		n--;
	}
	free(*tab);
}

static int	count_words(const char *s, char c)
{
	int	n;
	int	i;

	n = 0;
	i = 0;
	while (*s)
	{
		if (*s != c && n == 0)
		{
			i++;
			n = 1;
		}
		else if (*s == c && n == 1)
			n = 0;
		s++;
	}
	return (i);
}

static size_t	ft_len(const char *str, char c)
{
	int	n;

	n = 0;
	while (*str != c && *str)
	{
		n++;
		str++;
	}
	return (n);
}

static	void	conca(char ***tab, char const *s, int *pos, int len)
{
	int	n;
	int	i;

	n = *pos;
	i = 0;
	while (i < len)
	{
		(*tab)[n][i] = *s;
		s++;
		i++;
	}
	(*tab)[n][i] = '\0';
	*pos = n + 1;
}

char	**ft_split(char const *s, char c)
{
	char	**tab;
	int		words;
	int		n;
	int		o;

	words = count_words(s, c);
	tab = (char **)ft_calloc((words + 1), sizeof(char *));
	if (tab == 0)
		return (0);
	n = 0;
	o = 0;
	while (n < words)
	{
		if (*s != c && o == 0)
		{
			o = 1;
			tab[n] = malloc((ft_len(s, c) + 1) * sizeof(char));
			if (tab[n] == 0)
			{
				ft_free(&tab, n - 1);
				return (0);
			}
			conca(&tab, s, &n, ft_len(s, c));
		}
		else if (*s == c && o == 1)
			o = 0;
		s++;
	}
	return (tab);
}
