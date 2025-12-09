/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:32 by omawele           #+#    #+#             */
/*   Updated: 2025/12/09 12:53:33 by omawele          ###   ########.fr       */
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

int main(int argc, char **argv)
{
    t_var   var;
    int result;

    
    if (argc != 2)
        return (1);   
    // // Checking if the map is valid or not
    if(!create_map(&var, argv[1]))
    {
        ft_printf("Call create_map.\n");
        return (1);
    }
    result = is_map_valid(&var);
    if (result == 1)
    {
        ft_printf("The size of map is too much or not same for every lines.\n");
        return (1);
    }
    else if (result == 2)
    {
        ft_printf("There is a problem with characters in map.\n");
        return (2);
    }
    else if (result == 3)
    {
        ft_printf("There is no valid path in map.\n");
        return (3);
    }
    ft_printf("Player x : %d, y : %d\n", var.p.pos_x, var.p.pos_y);
    ft_printf("Map is valid.\n");
    free(var.map.map);
    // Initializing the window (struct etc) 

    // var.mlx.init = mlx_init();
    // var.mlx.win = mlx_new_window(var.mlx.init, MAX_WIDTH_WINDOW, MAX_HEIGHT_WINDOW, "Kapoumba");
    
    // // Loading and displaying images on the window
    // loadTextures(&var);
    // displayWall(&var);

	// mlx_hook(var.mlx.win, 2, 1L<<0, handleKey, &var);
	// mlx_hook(var.mlx.win, 2, 1L<<0, escWindow, &var);
	// mlx_hook(var.mlx.win, 17, 0, closeWindow, &var);
    // mlx_loop_hook(var.mlx.init, update, &var);
    // mlx_loop(var.mlx.init);
    // // mlx_destroy_window(var.mlx.init, var.mlx.win);
    return (0);
}
