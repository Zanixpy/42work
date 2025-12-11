/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:37 by omawele           #+#    #+#             */
/*   Updated: 2025/12/11 17:02:38 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"


static int check_load_textures(t_var *var)
{
    if (!var->t.player_up)
        return (1);
    if (!var->t.player_right)
        return (1);
    if (!var->t.player_left)
        return (1);
    if (!var->t.player_down)
        return (1);
    if (!var->t.wall)
        return (1);
    if (!var->t.space)
        return (1);
    if (!var->t.collectible)
        return (1);
    if (!var->t.exit_game)
        return (1);
    if (!var->t.black)
        return (1);
    return (0);
}


int   loadTextures(t_var *var)
{
    int width;
    int height;

    width = 64;
    height = 64;
    var->t.player_up = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_up.xpm", &width, &height);
    var->t.player_right = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_right.xpm", &width, &height);
    var->t.player_left = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_left.xpm", &width, &height);
    var->t.player_down = mlx_xpm_file_to_image(var->mlx.init, "./textures/player_down.xpm", &width, &height);
    var->t.wall = mlx_xpm_file_to_image(var->mlx.init, "./textures/wall.xpm", &width, &height);
    var->t.space = mlx_xpm_file_to_image(var->mlx.init, "./textures/floor.xpm", &width, &height);
    var->t.collectible = mlx_xpm_file_to_image(var->mlx.init, "./textures/coin.xpm", &width, &height);
    var->t.exit_game = mlx_xpm_file_to_image(var->mlx.init, "./textures/portal.xpm", &width, &height);
    var->t.black = mlx_xpm_file_to_image(var->mlx.init, "./textures/black", &width, &height);
    if (check_load_textures(var))
        return (1);
    return (0);
}




