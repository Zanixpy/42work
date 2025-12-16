/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:37 by omawele           #+#    #+#             */
/*   Updated: 2025/12/16 16:40:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void load_coins_textures(t_var *var)
{
    int	width;
	int	height;

	var->t.coins.c1 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c1.xpm",
			&width, &height);
    var->t.coins.c2 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c2.xpm",
			&width, &height);
    var->t.coins.c3 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c3.xpm",
			&width, &height);
    var->t.coins.c4 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c4.xpm",
			&width, &height);
    var->t.coins.c5 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c5.xpm",
			&width, &height);
    var->t.coins.c6 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c6.xpm",
			&width, &height);
    var->t.coins.c7 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c7.xpm",
			&width, &height);
    var->t.coins.c8 = mlx_xpm_file_to_image(var->mlx.init, "./textures/c8.xpm",
			&width, &height);
}

void load_textures(t_var *var)
{
	int	width;
	int	height;
    
    var->t.player_up = mlx_xpm_file_to_image(var->mlx.init,
			"./textures/player_up.xpm", &width, &height);
    var->t.player_down = mlx_xpm_file_to_image(var->mlx.init,
			"./textures/player_down.xpm", &width, &height);
	var->t.player_right = mlx_xpm_file_to_image(var->mlx.init,
			"./textures/player_right.xpm", &width, &height);
	var->t.player_left = mlx_xpm_file_to_image(var->mlx.init,
			"./textures/player_left.xpm", &width, &height);
    var->t.space = mlx_xpm_file_to_image(var->mlx.init, "./textures/floor.xpm",
			&width, &height);
	var->t.wall = mlx_xpm_file_to_image(var->mlx.init, "./textures/wall.xpm",
			&width, &height);
	var->t.exit_game = mlx_xpm_file_to_image(var->mlx.init,
			"./textures/portal.xpm", &width, &height);
	var->t.lava = mlx_xpm_file_to_image(var->mlx.init,
			"./textures/lava.xpm", &width, &height);
    load_coins_textures(var);
}
