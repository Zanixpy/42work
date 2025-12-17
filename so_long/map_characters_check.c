/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_characters_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:13:13 by omawele           #+#    #+#             */
/*   Updated: 2025/12/17 17:45:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	is_wscep(t_var *var, int x, int y)
{
	if (var->map.map[y][x] == 'P' && !var->cmap.player)
	{
		var->cmap.player = 1;
		var->p.pos_x_map = x;
		var->p.pos_y_map = y;
	}
	else if (var->map.map[y][x] == 'E' && !var->cmap.exit_game)
	{
		var->cmap.exit_game = 1;
		var->map.exit_x = x;
		var->map.exit_y = y;
	}
	else if (var->map.map[y][x] == 'C')
		var->cmap.coins += 1;
	else if (var->map.map[y][x] == '0')
		var->cmap.space = 1;
	else if (var->map.map[y][x] != '1' && var->map.map[y][x] != 'M')
		return (0);
	return (1);
}

static void	check_wall(t_var *var)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (var->map.map[0][x] && var->map.map[0][x] == '1'
		&& var->map.map[var->map.height - 1][x] == '1')
		x++;
	while ((y < var->map.height) && var->map.map[y][0] == '1'
		&& var->map.map[y][var->map.width - 1] == '1')
		y++;
	if (y != var->map.height)
		return ;
	var->cmap.wall = 1;
}

static int	check_characters_errors(t_var *var)
{
	if (!var->cmap.wall)
		return (0);
	if (!var->cmap.coins)
		return (0);
	if (!var->cmap.exit_game)
		return (0);
	if (!var->cmap.space)
		return (0);
	if (!var->cmap.player)
		return (0);
	return (1);
}

int	check_map_characters(t_var *var)
{
	int	x;
	int	y;

	y = 1;
	while (y < var->map.height - 1)
	{
		x = 1;
		while (x < var->map.width - 1)
		{
			if (!is_wscep(var, x, y))
				return (0);
			x++;
		}
		y++;
	}
	check_wall(var);
	return (check_characters_errors(var));
}
