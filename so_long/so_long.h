/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:49:19 by omawele           #+#    #+#             */
/*   Updated: 2025/12/12 16:52:02 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <math.h>

# define MAX_HEIGHT_WINDOW 1080
# define MAX_WIDTH_WINDOW 1920

typedef struct s_window {
    void    *init;
    void    *win;
} t_window;

typedef struct s__map
{
    char     **map;
    int     width;
    int     height;
} t_map;

typedef struct s__check_map
{
    int     wall;
    int     space;
    int     player;
    int     collectible;
    int     exit_game;
} t_check_map;

typedef struct s__check_map_path
{
    char    **tmap;
    int     valid_path;   
} t_check_map_path;

typedef struct s_textures {
    void    *player_up;
    void    *player_right;
    void    *player_left;
    void    *player_down;
    void    *wall;
    void    *space;
    void    *collectible;
    void    *exit_game;
    int width;
    int height;
} t_textures;

typedef struct s_player 
{
    int     pos_x;
    int     pos_y;
    int     pos_x_map;
    int     pos_y_map;
    int     coins;
    int     mouvement;
} t_player;

typedef struct s_var
{
    t_window mlx;
    t_player p;
    t_textures t;
    t_map map;
    t_check_map cmap;
    t_check_map_path cpath;
} t_var;

int   loadTextures(t_var *var);
int   handleKey(int keycode, t_var *var);
int escWindow(int keycode, t_var *var);
int   displayWall(t_var *var);
int     is_map_valid(t_var *var);
int check_map_size(t_var *var);
int check_map_characters(t_var *var);
char **create_map(t_var *var, char *filename);
void   check_map_path(t_var *var);
int build_window(t_var *var);
void    free_tab(char ***tab, int y);
void    free_textures(t_var *var);
void free_mlx(t_var *var);
void free_mlx_win(t_var *var);
int free_all(t_var *var);

#endif