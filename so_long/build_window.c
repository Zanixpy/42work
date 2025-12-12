/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:33:49 by omawele           #+#    #+#             */
/*   Updated: 2025/12/12 16:43:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void place_textures(t_var *var)
{
    int x;
    int y;
    
    y = 0;
    while (y < var->map.height)
    {
        x = 0;
        while (x < var->map.width)
        {
            if (var->map.map[y][x] == 'C') 
                mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.collectible, x * 64, y * 64);
            else if (var->map.map[y][x] == 'E')
                mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.exit_game, x * 64, y * 64);
            else if (var->map.map[y][x] == 'P')
                mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.player_right, x * 64, y * 64);
            else if (var->map.map[y][x] == '1')
                mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.wall, x * 64, y * 64);
            else if (var->map.map[y][x] == '0')
                mlx_put_image_to_window(var->mlx.init, var->mlx.win, var->t.space, x * 64, y * 64);
            x++;
        }
        y++;
    }
}

int build_window(t_var *var)
{
    int x;
    int y;

    x = var->map.width * 64;
    y = var->map.height * 64;  
    var->mlx.init = mlx_init();
    if (!var->mlx.init)
        return (free_tab(&var->map.map, var->map.height), \
        free_tab(&var->cpath.tmap, var->map.height), 0);
    var->mlx.win = mlx_new_window(var->mlx.init, x, y, "Kapoumba");
    if (!var->mlx.init || !var->mlx.win)
        return (free_tab(&var->map.map, var->map.height), \
        free_tab(&var->cpath.tmap, var->map.height), 0);
    loadTextures(var);
    place_textures(var);
    var->p.pos_x = var->p.pos_x_map * 64;
    var->p.pos_y = var->p.pos_y_map * 64;
    var->p.coins = 0;
    var->p.mouvement = 0;
    return (1);
}


