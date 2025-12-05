/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:37 by omawele           #+#    #+#             */
/*   Updated: 2025/12/05 16:54:20 by omawele          ###   ########.fr       */
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
    var->t.player_up = mlx_xpm_file_to_image(var->mlx.init, "./player_up.xpm", &width, &height);
    var->t.player_right = mlx_xpm_file_to_image(var->mlx.init, "./player_right.xpm", &width, &height);
    var->t.player_left = mlx_xpm_file_to_image(var->mlx.init, "./player_left.xpm", &width, &height);
    var->t.player_down = mlx_xpm_file_to_image(var->mlx.init, "./player_down.xpm", &width, &height);
    var->t.wall = mlx_xpm_file_to_image(var->mlx.init, "./wall.xpm", &width, &height);
    var->t.space = mlx_xpm_file_to_image(var->mlx.init, "./floor.xpm", &width, &height);
    var->t.collectible = mlx_xpm_file_to_image(var->mlx.init, "./coins.xpm", &width, &height);
    var->t.exit_game = mlx_xpm_file_to_image(var->mlx.init, "./portal.xpm", &width, &height);
    var->t.black = mlx_xpm_file_to_image(var->mlx.init, "./black", &width, &height);
    if (check_load_textures(var))
        return (1);
    return (0);
}

int   displayWall(t_var *var)
{
    int x;
    int x_rev;
    int y;
    int y_rev;
    
    x = 0;
    y = 0;
    x_rev = MAX_WIDTH_WINDOW - 64;
    y_rev = MAX_HEIGHT_WINDOW - 64;
    while (y < (MAX_HEIGHT_WINDOW - 64) && y_rev > 0)
    {
        mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.wall, x, y);
        mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.wall, x_rev, y_rev);
        y += 64;   
        y_rev -= 64;
    }
    while (x < (MAX_WIDTH_WINDOW - 64) && x_rev > 0)
    {
        mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.wall, x, y);
        mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.wall, x_rev, y_rev);
        x += 64;   
        x_rev -= 64;
    }
    return (0);
}



