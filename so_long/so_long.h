/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:49:19 by omawele           #+#    #+#             */
/*   Updated: 2025/12/02 17:31:29 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <math.h>

typedef struct s_window {
    void    *mlx;
    void    *mlx_win;
    void    *img;
    void    *img2;
} t_var;

typedef struct s_textures {
    void    *wall;
    void    *space;
    void    *collectible;
    void    *player;
} t_textures;

typedef struct s_player 
{
    int     pos_x;
    int     pos_y;
} t_player;

typedef struct s_coins 
{
    int     pos_x;
    int     pos_y;
} t_coins;

#endif