/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:19:17 by omawele           #+#    #+#             */
/*   Updated: 2025/12/16 16:40:52 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img_textures(t_var *var)
{
    if (var->t.player_up)
		mlx_destroy_image(var->mlx.init, var->t.player_up);
    if (var->t.player_down)
		mlx_destroy_image(var->mlx.init, var->t.player_down);
    if (var->t.player_right)
		mlx_destroy_image(var->mlx.init, var->t.player_right);
    if (var->t.player_left)
		mlx_destroy_image(var->mlx.init, var->t.player_left);
    if (var->t.space)
		mlx_destroy_image(var->mlx.init, var->t.space);
    if (var->t.wall)
		mlx_destroy_image(var->mlx.init, var->t.wall);
    if (var->t.exit_game)
		mlx_destroy_image(var->mlx.init, var->t.exit_game);
	if (var->t.lava)
		mlx_destroy_image(var->mlx.init, var->t.lava);
}

void	free_img_coins_textures(t_var *var)
{
	if (var->t.coins.c1)
		mlx_destroy_image(var->mlx.init, var->t.coins.c1);
    if (var->t.coins.c2)
		mlx_destroy_image(var->mlx.init, var->t.coins.c2);
    if (var->t.coins.c3)
		mlx_destroy_image(var->mlx.init, var->t.coins.c3);
    if (var->t.coins.c4)
		mlx_destroy_image(var->mlx.init, var->t.coins.c4);
    if (var->t.coins.c5)
		mlx_destroy_image(var->mlx.init, var->t.coins.c5);
    if (var->t.coins.c6)
		mlx_destroy_image(var->mlx.init, var->t.coins.c6);
    if (var->t.coins.c7)
		mlx_destroy_image(var->mlx.init, var->t.coins.c7);
    if (var->t.coins.c8)
		mlx_destroy_image(var->mlx.init, var->t.coins.c8);
}
