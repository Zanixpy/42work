/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_unit_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:08:24 by omawele           #+#    #+#             */
/*   Updated: 2025/12/16 16:49:42 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static void	set_checker(t_var *var)
{
	var->cmap.collectible = 0;
	var->cmap.player = 0;
	var->cmap.wall = 0;
	var->cmap.space = 0;
	var->cmap.exit_game = 0;
	var->cpath.valid_path = 0;
}

int	check_map_size(t_var *var)
{
	int	x;
	int	y;
	int	cmp;

	y = 0;
	cmp = 0;
	while (var->map.map[y][cmp] != '\0')
		cmp++;
	y++;
	while (var->map.map[y] != NULL)
	{
		x = 0;
		while (var->map.map[y][x] != '\0')
			x++;
		if (cmp != x)
			return (0);
		y++;
	}
	var->map.width = x;
	return (1);
}

static void	path_search(char ***tab, int x, int y)
{
	if ((*tab)[y][x] == '1' || (*tab)[y][x] == 'T' || (*tab)[y][x] == 'M')
		return ;
	(*tab)[y][x] = 'T';
	path_search(tab, x, y + 1);
	path_search(tab, x, y - 1);
	path_search(tab, x + 1, y);
	path_search(tab, x - 1, y);
}

void	check_map_path(t_var *var)
{
	int	y;
	int	x;

	path_search(&(var->cpath.tmap), var->p.pos_x_map, var->p.pos_y_map);
	y = 1;
	while (y < var->map.height)
	{
		x = 1;
		while (x < var->map.width - 1)
		{
			if (var->cpath.tmap[y][x] == 'C' || var->cpath.tmap[y][x] == 'E'
				|| var->cpath.tmap[y][x] == 'P')
				return ;
			x++;
		}
		y++;
	}
	var->cpath.valid_path = 1;
}

int	is_map_valid(t_var *var)
{
	set_checker(var);
	if (!check_map_size(var))
		return (1);
	if (!check_map_characters(var))
		return (2);
	check_map_path(var);
	if (!var->cpath.valid_path)
		return (3);
	return (0);
}
