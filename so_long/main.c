/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:32 by omawele           #+#    #+#             */
/*   Updated: 2025/12/03 18:57:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>
#include <stdio.h>

int press_key(int keycode, t_window *var)
{
    if (keycode == 65307)
        mlx_destroy_window(var->mlx, var->mlx_win);
    if (keycode == 'a')
    {
        var->player_x -= 64;
        mlx_put_image_to_window(var->mlx,var->mlx_win,var->img, var->player_x, var->player_y);    
        mlx_put_image_to_window(var->mlx,var->mlx_win,var->img2, var->player_x + 64, var->player_y);
    }
    if (keycode == 's')
        mlx_put_image_to_window(var->mlx,var->mlx_win,var->img, var->player_x, var->player_y + 64);
    if (keycode == 'd')
        mlx_put_image_to_window(var->mlx,var->mlx_win,var->img, var->player_x + 64, var->player_y);
    if (keycode == 'w')
        mlx_put_image_to_window(var->mlx,var->mlx_win,var->img, var->player_x, var->player_y - 64);
    return (0);
}

int close_win(t_ *var)
{
    mlx_destroy_window(var->mlx, var->mlx_win);
    return (0);
}

int update(t_var *var)
{
    (void)var;
    return (0);
}

int main(void)
{
    int		width;
	int		height;
    t_window   mlx;
    t_player    p;
    t_textures  t;

    mlx.init = mlx_init();
    mlx.win = mlx_new_window(mlx.init, 1920, 1080, "Kapoumba");
    t.black = mlx_xpm_file_to_image(mlx.init, "./black", &width, &height);

	mlx_hook(var.mlx_win, 2, 1L<<0, press_key, &var);
	mlx_hook(var.mlx_win, 17, 0, close_win, &var);
    mlx_loop_hook(var.mlx, update, &var);
    mlx_loop(var.mlx);
    return (0);
}