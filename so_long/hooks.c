/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/04 18:07:40 by omawele           #+#    #+#             */
/*   Updated: 2025/12/05 16:02:01 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int handleKey(int keycode, t_var *var)
{
    if (keycode == 'a')
    {
        var->p.pos_x -= 64;
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.player_left, var->p.pos_x, var->p.pos_y);
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.black, var->p.pos_x + 64, var->p.pos_y);    
    }
    if (keycode == 's')
    {
        var->p.pos_y += 64;
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.player_down, var->p.pos_x, var->p.pos_y);
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.black, var->p.pos_x, var->p.pos_y - 64);    
    }
    if (keycode == 'd')
    {
        var->p.pos_x += 64;
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.player_right, var->p.pos_x, var->p.pos_y);
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.black, var->p.pos_x - 64, var->p.pos_y);        
    }
    if (keycode == 'w')
    {
        var->p.pos_y -= 64;   
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.player_up, var->p.pos_x, var->p.pos_y);
        mlx_put_image_to_window(var->mlx.init,var->mlx.win,var->t.black, var->p.pos_x, var->p.pos_y + 64);      
    }
    return (0);
}

int escWindow(int keycode, t_var *var)
{
    if (keycode == 65307)
        mlx_destroy_window(var->mlx.init, var->mlx.win);       
    return (0);
}
int closeWindow(t_var *var)
{
    mlx_destroy_window(var->mlx.init, var->mlx.win);
    return (0);
}
