/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:37 by omawele           #+#    #+#             */
/*   Updated: 2025/12/05 00:25:47 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


static int check_load_textures(t_textures *t)
{
    if (!t->player_up)
        return (1);
    if (!t->player_right)
        return (1);
    if (!t->player_left)
        return (1);
    if (!t->player_down)
        return (1);
    if (!t->wall)
        return (1);
    if (!t->space)
        return (1);
    if (!t->collectible)
        return (1);
    if (!t->exit_game)
        return (1);
    if (!t->black)
        return (1);
    return (0);
}


int   loadTextures(t_window *mlx, t_textures *t)
{
    int width;
    int height;

    width = 64;
    height = 64;
    t->player_up = mlx_xpm_file_to_image(mlx->init, "./player_up.xpm", &width, &height);
    t->player_right = mlx_xpm_file_to_image(mlx->init, "./player_right.xpm", &width, &height);
    t->player_left = mlx_xpm_file_to_image(mlx->init, "./player_left.xpm", &width, &height);
    t->player_down = mlx_xpm_file_to_image(mlx->init, "./player_down.xpm", &width, &height);
    t->wall = mlx_xpm_file_to_image(mlx->init, "./wall.xpm", &width, &height);
    t->space = mlx_xpm_file_to_image(mlx->init, "./floor.xpm", &width, &height);
    t->collectible = mlx_xpm_file_to_image(mlx->init, "./coins.xpm", &width, &height);
    t->exit_game = mlx_xpm_file_to_image(mlx->init, "./portal.xpm", &width, &height);
    t->black = mlx_xpm_file_to_image(mlx->init, "./black", &width, &height);
    if (check_load_textures(t))
        return (1);
    return (0);
}



