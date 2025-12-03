/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:37 by omawele           #+#    #+#             */
/*   Updated: 2025/12/03 18:26:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void   load_player(t_window *mlx, t_player *p, int *width, int *height)
{
    p->player_up = mlx_xpm_file_to_image(mlx->init, "./player_up.xpm", width, height);
    p->player_right = mlx_xpm_file_to_image(mlx->init, "./player_right.xpm", width, height);
    p->player_left = mlx_xpm_file_to_image(mlx->init, "./player_left.xpm", width, height);
    p->player_down = mlx_xpm_file_to_image(mlx->init, "./player_down.xpm", width, height);
    p->pos_x = 500;
    p->pos_y = 250;
}

void   load_wall(t_window *mlx, t_textures *t, int *width, int *height)
{
    t->wall = mlx_xpm_file_to_image(mlx->init, "./wall.xpm", width, height);
    
}

void   load_space(t_window *mlx, t_textures *t, int *width, int *height)
{
    t->space = mlx_xpm_file_to_image(mlx->init, "./floor.xpm", width, height);

    
}

void   load_collectibles(t_window *mlx, t_textures *t, int *width, int *height)
{
    t->collectible = mlx_xpm_file_to_image(mlx->init, "./coins.xpm", width, height);

    
}

void   load_exit(t_window *mlx, t_textures *t, int *width, int *height)
{
    t->exit_game = mlx_xpm_file_to_image(mlx->init, "./portal.xpm", width, height);

    
}