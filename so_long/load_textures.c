/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:37 by omawele           #+#    #+#             */
/*   Updated: 2025/12/15 16:17:29 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

static void free_img(t_var *var, int n)
{
    if (n == 1)
        mlx_destroy_image(var->mlx.init, var->t.player_up);
    else if (n == 2)
        mlx_destroy_image(var->mlx.init, var->t.player_right);
    else if (n == 3)
        mlx_destroy_image(var->mlx.init, var->t.player_left);
    else if (n == 4)
        mlx_destroy_image(var->mlx.init, var->t.wall);
    else if (n == 5)
        mlx_destroy_image(var->mlx.init, var->t.space);
    else if (n == 6)
        mlx_destroy_image(var->mlx.init, var->t.collectible);
}

static void free_player(t_var *var)
{
    mlx_destroy_image(var->mlx.init, var->t.player_up);
    mlx_destroy_image(var->mlx.init, var->t.player_left);
    mlx_destroy_image(var->mlx.init, var->t.player_right);
    mlx_destroy_image(var->mlx.init, var->t.player_down);
}

static int load_player(t_var *var)
{
    int width;
    int height;

    var->t.player_up = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_up.xpm", &width, &height);
    if (!var->t.player_up)
        return (0);
    var->t.player_right = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_right.xpm", &width, &height);
    if (!var->t.player_right)
        return (free_img(var, 1), 0);
    var->t.player_left = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_left.xpm", &width, &height);
    if (!var->t.player_left)
        return (free_img(var, 1), free_img(var, 2),0);
    var->t.player_down = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_down.xpm", &width, &height);
    if (!var->t.player_down)
        return (free_img(var, 1), free_img(var, 2), free_img(var, 3),0);
    return (1);
}

int   loadTextures(t_var *var)
{
    int width;
    int height;
    
    if (!load_player(var))
        return (0);
    var->t.wall = mlx_xpm_file_to_image(var->mlx.init, "./textures/wall.xpm", &width, &height);
    if (!var->t.wall)
        return (free_player(var), 0);
    var->t.space = mlx_xpm_file_to_image(var->mlx.init, "./textures/floor.xpm", &width, &height);
    if (!var->t.space)
        return (free_player(var), free_img(var, 4), 0);
    var->t.collectible = mlx_xpm_file_to_image(var->mlx.init, "./textures/coin.xpm", &width, &height);
    if (!var->t.collectible)
        return (free_player(var), free_img(var, 4), free_img(var, 5), 0);
    var->t.exit_game = mlx_xpm_file_to_image(var->mlx.init, "./textures/portal.xpm", &width, &height);
    if (!var->t.exit_game)
        return (free_player(var), free_img(var, 4), free_img(var, 5), free_img(var, 6), 0);
    return (1);
}




