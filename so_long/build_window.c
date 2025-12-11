/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   build_window.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/11 16:33:49 by omawele           #+#    #+#             */
/*   Updated: 2025/12/11 17:03:13 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int build_window(t_var *var)
{
    int x;
    int y;

    x = var->map.width * 64;
    y = var->map.height * 64;
    if (x > 1920 || y > 1080)
        return (0);   
    var->mlx.init = mlx_init();
    var->mlx.win = mlx_new_window(var->mlx.init, x, y, "Kapoumba");
    if (!var->mlx.init || !var->mlx.win)
        return (0);
    loadTextures(var);
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
    return (1);
}
