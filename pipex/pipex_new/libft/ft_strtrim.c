/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/08 11:47:36 by omawele           #+#    #+#             */
/*   Updated: 2026/01/20 15:31:37 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	chr(char c, char const *set)
{
	unsigned int	n;

	n = 0;
	while (set[n])
	{
		if (ft_toupper(c) == set[n] || ft_tolower(c) == set[n] || c == set[n])
			return (1);
		n++;
	}
	return (0);
}

static char	*empty(void)
{
	char	*tmp;

	tmp = malloc(sizeof(char));
	if (tmp == NULL)
		return (NULL);
	tmp[0] = '\0';
	return (tmp);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*tmp;
	int		j;
	int		i;
	int		n;

	j = 0;
	i = ft_strlen(s1);
	if (i == 0)
		return (empty());
	while (chr(s1[j], set) == 1)
		j++;
	while (chr(s1[i - 1], set) == 1)
		i--;
	i -= j;
	tmp = malloc((i + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	n = 0;
	while (n < i)
	{
		tmp[n] = s1[j++];
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}
