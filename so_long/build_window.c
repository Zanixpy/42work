/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:33:49 by omawele           #+#    #+#             */
/*   Updated: 2025/12/17 17:30:18 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	place_textures(t_var *var, int x, int y)
{
	while (++y < var->map.height)
	{
		x = -1;
		while (++x < var->map.width)
		{
			if (var->map.map[y][x] == 'C')
				mlx_put_image_to_window(var->mlx.init, var->mlx.win,
					var->t.coins.c1, x * 64, y * 64);
			else if (var->map.map[y][x] == 'E')
				mlx_put_image_to_window(var->mlx.init, var->mlx.win,
					var->t.space, x * 64, y * 64);
			else if (var->map.map[y][x] == 'P')
				mlx_put_image_to_window(var->mlx.init, var->mlx.win,
					var->t.player_right, x * 64, y * 64);
			else if (var->map.map[y][x] == '1')
				mlx_put_image_to_window(var->mlx.init, var->mlx.win,
					var->t.wall, x * 64, y * 64);
			else if (var->map.map[y][x] == '0')
				mlx_put_image_to_window(var->mlx.init, var->mlx.win,
					var->t.space, x * 64, y * 64);
			else if (var->map.map[y][x] == 'M')
				mlx_put_image_to_window(var->mlx.init, var->mlx.win,
					var->t.lava, x * 64, y * 64);
		}
	}
}

void	is_winner(int check)
{
	char	*win;
	char	*lose;

	win = "You won";
	lose = "You lost";
	if (check)
		ft_printf("------%s------\n", win);
	else
		ft_printf("------%s------\n", lose);
}

void	unlock_exit_game(t_var *var)
{
	if (var->p.coins == var->cmap.coins)
		var->p.unlock_exit = 1;
	if (var->p.unlock_exit)
	{
		mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.exit_game,
			var->map.exit_x * 64, var->map.exit_y * 64);
	}
}

int	build_window(t_var *var)
{
	int	x;
	int	y;

	x = var->map.width * 64;
	y = var->map.height * 64;
	var->mlx.init = mlx_init();
	if (!var->mlx.init)
		return (free_var_tab(var), 1);
	var->mlx.win = mlx_new_window(var->mlx.init, x, y, "Kapoumba");
	if (!var->mlx.win)
		return (free_var_tab(var), free_mlx(var), 1);
	if (is_textures_valid(var))
		return (free_var_tab(var), free_mlx_win(var), free_mlx(var), 2);
	place_textures(var, -1, -1);
	var->p.pos_x = var->p.pos_x_map * 64;
	var->p.pos_y = var->p.pos_y_map * 64;
	var->p.coins = 0;
	var->p.mouvement = 0;
	var->p.unlock_exit = 0;
	return (0);
}
