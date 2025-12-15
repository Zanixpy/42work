/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/15 21:19:17 by omawele           #+#    #+#             */
/*   Updated: 2025/12/15 21:46:00 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_img_textures(t_var *var, int n)
{
	if (n >= 1)
		mlx_destroy_image(var->mlx.init, var->t.player_up);
	if (n >= 2)
		mlx_destroy_image(var->mlx.init, var->t.player_down);
	if (n >= 3)
		mlx_destroy_image(var->mlx.init, var->t.player_right);
	if (n >= 4)
		mlx_destroy_image(var->mlx.init, var->t.player_left);
	if (n >= 5)
		mlx_destroy_image(var->mlx.init, var->t.space);
	if (n >= 7)
		mlx_destroy_image(var->mlx.init, var->t.wall);
    if (n == 8)
		mlx_destroy_image(var->mlx.init, var->t.exit_game);
}

void	free_img_coins_textures(t_var *var, int n)
{
	if (n >= 1)
		mlx_destroy_image(var->mlx.init, var->t.coins.c1);
	if (n >= 2)
		mlx_destroy_image(var->mlx.init, var->t.coins.c2);
	if (n >= 3)
		mlx_destroy_image(var->mlx.init, var->t.coins.c3);
	if (n >= 4)
		mlx_destroy_image(var->mlx.init, var->t.coins.c4);
	if (n >= 5)
		mlx_destroy_image(var->mlx.init, var->t.coins.c5);
	if (n >= 7)
		mlx_destroy_image(var->mlx.init, var->t.coins.c6);
    if (n >= 8)
		mlx_destroy_image(var->mlx.init, var->t.coins.c7);
    if (n == 9)
		mlx_destroy_image(var->mlx.init, var->t.coins.c8);
}
