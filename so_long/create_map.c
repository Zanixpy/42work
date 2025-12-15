/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:42:43 by omawele           #+#    #+#             */
/*   Updated: 2025/12/15 20:21:39 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	free_tab(char ***tab, int y)
{
	if (y > 0)
	{
		while (--y >= 0)
			free((*tab)[y]);
	}
	free((*tab));
}

static int	count_line(t_var *var, char *filename)
{
	char	*line;
	int		fd;
	int		count;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (0);
	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		count++;
		free(line);
		line = get_next_line(fd);
	}
	var->map.height = count;
	return (close(fd), count);
}

static int	malloc_line(char ***tab, char **line, int y)
{
	int	size;
	int	x;
	int	nul;

	if (!(*line))
		return (free_tab(tab, y), 0);
	size = ft_strlen((*line));
	nul = 1;
	if (ft_strchr((*line), '\n'))
		nul = 0;
	(*tab)[y] = malloc((size + nul) * sizeof(char));
	if (!(*tab)[y])
		return (free(*line), free_tab(tab, y), 0);
	x = 0;
	while (x < size)
	{
		(*tab)[y][x] = (*line)[x];
		x++;
	}
	(*tab)[y][(size + nul) - 1] = '\0';
	return (1);
}

static char	**create_map(char *filename, int size)
{
	char	**tab;
	char	*line;
	int		fd;
	int		y;

	fd = open(filename, O_RDONLY);
	if (fd < 0)
		return (NULL);
	tab = malloc(size * sizeof(char *));
	if (!tab)
		return (close(fd), NULL);
	y = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		if (!malloc_line(&tab, &line, y))
			return (close(fd), NULL);
		y++;
		free(line);
		line = get_next_line(fd);
	}
	tab[size - 1] = NULL;
	return (close(fd), tab);
}

int	init_map(t_var *var, char *filename)
{
	int	size;

	size = count_line(var, filename) + 1;
	if (size == 0)
		return (1);
	var->map.map = create_map(filename, size);
	if (!var->map.map)
		return (1);
	var->cpath.tmap = create_map(filename, size);
	if (!var->cpath.tmap)
		return (free_tab(&var->map.map, var->map.height), 1);
	return (0);
}
