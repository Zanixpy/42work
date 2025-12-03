/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:49:19 by omawele           #+#    #+#             */
/*   Updated: 2025/12/03 18:28:19 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include <math.h>

typedef struct s_window {
    void    *init;
    void    *win;
} t_window;

typedef struct s_check_map 
{
    int     wall;
    int     space;
    int     collectible;
    int     player;
    int     exit_game;
} t_check_map;

typedef struct s_textures {
    void    *wall;
    void    *space;
    void    *collectible;
    void    *exit_game;
    void    *black;
} t_textures;

typedef struct s_player 
{
    void    *player_up;
    void    *player_right;
    void    *player_left;
    void    *player_down;
    int     pos_x;
    int     pos_y;
} t_player;

#endif