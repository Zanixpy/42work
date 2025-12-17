/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 15:17:53 by omawele           #+#    #+#             */
/*   Updated: 2025/12/17 16:26:18 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>

int	free_all(t_var *var)
{
	free_textures(var);
	free_var_tab(var);
	free_mlx_win(var);
	free_mlx(var);
	exit(0);
	return (0);
}

void	free_var_tab(t_var *var)
{
	int	y;

	y = var->map.height;
	if (y > 0)
	{
		while (--y >= 0)
		{
			free((var->map.map)[y]);
			free((var->cpath.tmap)[y]);
		}
	}
	free(var->map.map);
	free(var->cpath.tmap);
}

void	free_textures(t_var *var)
{
	mlx_destroy_image(var->mlx.init, var->t.player_up);
	mlx_destroy_image(var->mlx.init, var->t.player_left);
	mlx_destroy_image(var->mlx.init, var->t.player_right);
	mlx_destroy_image(var->mlx.init, var->t.player_down);
	mlx_destroy_image(var->mlx.init, var->t.exit_game);
	mlx_destroy_image(var->mlx.init, var->t.space);
	mlx_destroy_image(var->mlx.init, var->t.wall);
	mlx_destroy_image(var->mlx.init, var->t.lava);
	mlx_destroy_image(var->mlx.init, var->t.coins.c1);
	mlx_destroy_image(var->mlx.init, var->t.coins.c2);
	mlx_destroy_image(var->mlx.init, var->t.coins.c3);
	mlx_destroy_image(var->mlx.init, var->t.coins.c4);
	mlx_destroy_image(var->mlx.init, var->t.coins.c5);
	mlx_destroy_image(var->mlx.init, var->t.coins.c6);
	mlx_destroy_image(var->mlx.init, var->t.coins.c7);
	mlx_destroy_image(var->mlx.init, var->t.coins.c8);
}

void	free_mlx(t_var *var)
{
	mlx_destroy_display(var->mlx.init);
	free(var->mlx.init);
}

void	free_mlx_win(t_var *var)
{
	mlx_destroy_window(var->mlx.init, var->mlx.win);
}
