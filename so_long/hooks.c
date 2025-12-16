/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:07:40 by omawele           #+#    #+#             */
/*   Updated: 2025/12/16 16:44:10 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	left(t_var *var)
{
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map - 1] == '1')
		return (0);
	else if (var->map.map[var->p.pos_y_map][var->p.pos_x_map - 1] == 'E'
		&& var->p.coins != var->cmap.collectible)
		return (0);
	var->p.pos_x -= 64;
	var->p.pos_x_map -= 1;
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.player_left,
		var->p.pos_x, var->p.pos_y);
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.space,
		var->p.pos_x + 64, var->p.pos_y);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'C')
	{
		var->p.coins += 1;
		var->map.map[var->p.pos_y_map][var->p.pos_x_map] = '0';
	}
	else if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'E'
		&& var->p.coins == var->cmap.collectible)
		return (free_all(var), 0);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'M')
		return (free_all(var), 0);
	return (1);
}

static int	down(t_var *var)
{
	if (var->map.map[var->p.pos_y_map + 1][var->p.pos_x_map] == '1')
		return (0);
	else if (var->map.map[var->p.pos_y_map + 1][var->p.pos_x_map] == 'E'
		&& var->p.coins != var->cmap.collectible)
		return (0);
	var->p.pos_y += 64;
	var->p.pos_y_map += 1;
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.player_down,
		var->p.pos_x, var->p.pos_y);
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.space,
		var->p.pos_x, var->p.pos_y - 64);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'C')
	{
		var->p.coins += 1;
		var->map.map[var->p.pos_y_map][var->p.pos_x_map] = '0';
	}
	else if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'E'
		&& var->p.coins == var->cmap.collectible)
		return (free_all(var), 0);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'M')
		return (free_all(var), 0);
	return (1);
}

static int	right(t_var *var)
{
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map + 1] == '1')
		return (0);
	else if (var->map.map[var->p.pos_y_map][var->p.pos_x_map + 1] == 'E'
		&& var->p.coins != var->cmap.collectible)
		return (0);
	var->p.pos_x += 64;
	var->p.pos_x_map += 1;
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.player_right,
		var->p.pos_x, var->p.pos_y);
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.space,
		var->p.pos_x - 64, var->p.pos_y);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'C')
	{
		var->p.coins += 1;
		var->map.map[var->p.pos_y_map][var->p.pos_x_map] = '0';
	}
	else if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'E'
		&& var->p.coins == var->cmap.collectible)
		return (free_all(var), 0);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'M')
		return (free_all(var), 0);
	return (1);
}

static int	up(t_var *var)
{
	if (var->map.map[var->p.pos_y_map - 1][var->p.pos_x_map] == '1')
		return (0);
	else if (var->map.map[var->p.pos_y_map - 1][var->p.pos_x_map] == 'E'
		&& var->p.coins != var->cmap.collectible)
		return (0);
	var->p.pos_y -= 64;
	var->p.pos_y_map -= 1;
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.player_up,
		var->p.pos_x, var->p.pos_y);
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.space,
		var->p.pos_x, var->p.pos_y + 64);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'C')
	{
		var->p.coins += 1;
		var->map.map[var->p.pos_y_map][var->p.pos_x_map] = '0';
	}
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'E'
		&& var->p.coins == var->cmap.collectible)
		return (free_all(var), 0);
	if (var->map.map[var->p.pos_y_map][var->p.pos_x_map] == 'M')
		return (free_all(var), 0);
	return (1);
}

int	handle_key(int keycode, t_var *var)
{
	char 	*s;
	int		result;

	result = 0;
	if (keycode == 65307)
		return (free_all(var), 1);
	else if (keycode == 'a')
		result = left(var);
	else if (keycode == 's')
		result = down(var);
	else if (keycode == 'd')
		result = right(var);
	else if (keycode == 'w')
		result = up(var);
	if (result)
		var->p.mouvement += 1;
	s = ft_itoa(var->p.mouvement);
	if (!s)
		return (free_all(var), 1);
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.wall, 0, 0);
	mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.wall, 64, 0);
	mlx_string_put(var->mlx.init, var->mlx.win, 8, 30, 0xFFFFFF, "Mouvement :");
	mlx_string_put(var->mlx.init, var->mlx.win, 78, 31, 0xFFFFFF, s);
	free(s);
	return (0);
}
