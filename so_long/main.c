/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:32 by omawele           #+#    #+#             */
/*   Updated: 2025/12/05 18:18:36 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include "so_long.h"
#include <sys/time.h>
#include <stdio.h>


int update(t_window *mlx)
{
    (void)mlx;
    return (0);
}

int main(void)
{
    t_var   var;


    var.mlx.init = mlx_init();
    var.mlx.win = mlx_new_window(var.mlx.init, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, "Kapoumba");
    
    loadTextures(&var);
    displayWall(&var);

	mlx_hook(var.mlx.win, 2, 1L<<0, handleKey, &var);
	mlx_hook(var.mlx.win, 2, 1L<<0, escWindow, &var);
	mlx_hook(var.mlx.win, 17, 0, closeWindow, &var);
    mlx_loop_hook(var.mlx.init, update, &var);
    mlx_loop(var.mlx.init);
    // mlx_destroy_window(var.mlx.init, var.mlx.win);
    return (0);
}