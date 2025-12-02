#include "so_long.h"
#include <sys/time.h>
#include <stdio.h>

int press_key(int keycode, t_var *var)
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

int close_win(t_var *var)
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
    int		img_width;
	int		img_height;
    t_var   var;


    var.player_x = 500;
    var.player_y = 250;
	var.mlx = mlx_init();
    var.mlx_win = mlx_new_window(var.mlx, 1920, 1080, "So_long");
    var.img = mlx_xpm_file_to_image(var.mlx, "./llyod.xpm", &img_width, &img_height);
	var.img2 = mlx_xpm_file_to_image(var.mlx, "./black.xpm", &img_width, &img_height);
	mlx_put_image_to_window(var.mlx,var.mlx_win,var.img, var.player_x, var.player_y);
	mlx_hook(var.mlx_win, 2, 1L<<0, press_key, &var);
	mlx_hook(var.mlx_win, 17, 0, close_win, &var);
    mlx_loop_hook(var.mlx, update, &var);
    mlx_loop(var.mlx);
    return (0);
}