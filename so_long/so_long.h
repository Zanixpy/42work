/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:49:19 by omawele           #+#    #+#             */
/*   Updated: 2025/12/06 19:57:00 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
#define SO_LONG_H

#include "mlx/mlx.h"
#include "libft/libft.h"
#include <math.h>

#define MAX_WIDTH_WINDOW 1920
#define MAX_HEIGHT_WINDOW 1020

typedef struct s_window {
    void    *init;
    void    *win;
} t_window;

typedef struct s__map
{
    char     map[MAX_HEIGHT_WINDOW][MAX_WIDTH_WINDOW];
    int     xsize;
    int     ysize;
} t_map;

typedef struct s__check_map
{
    int     wall;
    int     space;
    int     player;
    int     collectible;
    int     exit_game;
    int     pos_x;
    int     pos_y;
} t_check_map;

typedef struct s_textures {
    void    *player_up;
    void    *player_right;
    void    *player_left;
    void    *player_down;
    void    *wall;
    void    *space;
    void    *collectible;
    void    *exit_game;
    void    *black;
} t_textures;

typedef struct s_player 
{
    int     pos_x;
    int     pos_y;
} t_player;

typedef struct s_var
{
    t_window mlx;
    t_player p;
    t_textures t;
    t_map map;
    t_check_map cmap;
} t_var;

int   loadTextures(t_var *var);
int   handleKey(int keycode, t_var *var);
int escWindow(int keycode, t_var *var);
int closeWindow(t_var *var);
int   displayWall(t_var *var);
int     is_map_valid(t_var *var, int fd);
int check_xsize(t_var *var);
int check_ysize(t_var *var);
int check_characters(t_var *var);

#endif