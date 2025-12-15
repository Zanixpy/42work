/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 10:49:19 by omawele           #+#    #+#             */
/*   Updated: 2025/12/15 21:53:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <math.h>
# include <sys/time.h>

typedef struct s_window
{
	void				*init;
	void				*win;
}						t_window;

typedef struct s__map
{
	char				**map;
	int					width;
	int					height;
}						t_map;

typedef struct s__check_map
{
	int					wall;
	int					space;
	int					player;
	int					collectible;
	int					exit_game;
}						t_check_map;

typedef struct s__check_map_path
{
	char				**tmap;
	int					valid_path;
}						t_check_map_path;

typedef struct s_textures
{
	void				*player_up;
	void				*player_right;
	void				*player_left;
	void				*player_down;
	void				*wall;
	void				*space;
    t_coins_animations  coins;
	void				*exit_game;
}						t_textures;

typedef struct s_coins_animations
{
	void				*c1;
	void				*c2;
	void				*c3;
	void				*c4;
	void				*c5;
	void				*c6;
	void				*c7;
	void				*c8;
}						t_coins_animations;

typedef struct s_player
{
	int					pos_x;
	int					pos_y;
	int					pos_x_map;
	int					pos_y_map;
	int					coins;
	int					mouvement;
}						t_player;

typedef struct s_var
{
	t_window			mlx;
	t_player			p;
	t_textures			t;
	t_map				map;
	t_check_map			cmap;
	t_check_map_path	cpath;
}						t_var;

void						load_textures(t_var *var);
void load_coins_textures(t_var *var);
int						handle_key(int keycode, t_var *var);
int						is_map_valid(t_var *var);
int						init_map(t_var *var, char *filename);
int						check_map_characters(t_var *var);
int						build_window(t_var *var);
void					free_textures(t_var *var);
void					free_mlx(t_var *var);
void					free_mlx_win(t_var *var);
int						free_all(t_var *var);
void					free_var_tab(t_var *var);
int check_coins_textures(t_var *var);
int check_textures(t_var *var);
void	free_img_coins_textures(t_var *var, int n);
void	free_img_textures(t_var *var, int n);
int is_textures_valid(t_var *var);

#endif