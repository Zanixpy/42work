/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:32 by omawele           #+#    #+#             */
/*   Updated: 2025/12/04 18:26:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <sys/time.h>
#include <stdio.h>

int press_key(int keycode, t_window *var)
{
  
    return (0);
}

int close_win(t_V  _ *var)
{

}

int update(t_window *mlx)
{
    (void)mlx;
    return (0);
}

int main(void)
{
    int		width;
	int		height;
    t_var   var;


    var.mlx.init = mlx_init();
    var.mlx.win = mlx_new_window(var.mlx.init, 1920, 1080, "Kapoumba");

	mlx_hook(var.mlx.win, 2, 1L<<0, press_key, &var);
	mlx_hook(mlx.win, 17, 0, close_win, &var);
    mlx_loop_hook(mlx.init, update, &var);
    mlx_loop(var.mlx.init);

    mlx_destroy_display(mlx.init);
    free(mlx.init);
    return (0);
}