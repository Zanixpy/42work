/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:32 by omawele           #+#    #+#             */
/*   Updated: 2025/12/17 17:31:05 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(char *s)
{
	char	**filename;
	int		fd;
	int		size;
	int		i;

	if (!s)
		return (1);
	i = 0;
	filename = ft_split(s, '/');
	if (!filename)
		return (1);
	while (filename[i] != NULL)
		i++;
	size = ft_strlen(filename[i - 1]);
	if (size == 4)
		return (free_tab(&filename, i), 1);
	if (!(filename[i - 1][size - 1] == 'r' && filename[i - 1][size - 2] == 'e'
			&& filename[i - 1][size - 3] == 'b' && filename[i - 1][size
			- 4] == '.'))
		return (free_tab(&filename, i), 1);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (free_tab(&filename, i), 1);
	return (free_tab(&filename, i), close(fd), 0);
}

static void	error_check(char c, int n)
{
	write(2, "Error\n", 6);
	if (c == 'f')
		write(2, "Bad file format or file descriptor\n", 35);
	else if (c == 'm')
	{
		if (n == 1)
			write(2, "Map size is invalid\n", 20);
		else if (n == 2)
			write(2, "Map characters is invalid\n", 26);
		else if (n == 3)
			write(2, "No path found in map\n", 21);
	}
	else if (c == 'c')
		write(2, "Problem with parsing file into tab\n", 35);
	else if (c == 'b')
		write(2, "Problem on creating the window or charging textures\n", 52);
}

void	update_coins(t_var *var, void *img)
{
	int	x;
	int	y;

	y = 1;
	while (y < var->map.height)
	{
		x = 1;
		while (var->map.map[y][x])
		{
			if (var->map.map[y][x] == 'C')
				mlx_put_image_to_window(var->mlx.init, var->mlx.win, img, x
					* 64, y * 64);
			x++;
		}
		y++;
	}
}

int	update(t_var *var)
{
	static int	ms = 0;

	unlock_exit_game(var);
	if (ms == 200)
		update_coins(var, var->t.coins.c1);
	if (ms == 1200)
		update_coins(var, var->t.coins.c2);
	if (ms == 2200)
		update_coins(var, var->t.coins.c3);
	if (ms == 3200)
		update_coins(var, var->t.coins.c4);
	if (ms == 4200)
		update_coins(var, var->t.coins.c5);
	if (ms == 5200)
		update_coins(var, var->t.coins.c6);
	if (ms == 6200)
		update_coins(var, var->t.coins.c7);
	if (ms == 7200)
	{
		update_coins(var, var->t.coins.c8);
		ms = 0;
	}
	ms++;
	return (0);
}

int	main(int argc, char **argv)
{
	t_var	var;
	int		result;

	if (argc != 2)
		return (1);
	if (check_file(argv[1]))
		return (error_check('f', 0), 2);
	if (init_map(&var, argv[1]))
		return (error_check('c', 0), 3);
	result = is_map_valid(&var);
	if (result)
		return (free_var_tab(&var), error_check('m', result), 4);
	if (build_window(&var))
	{
		return (error_check('b', 0), 5);
	}
	mlx_hook(var.mlx.win, 2, 1L << 0, handle_key, &var);
	mlx_hook(var.mlx.win, 17, 0, free_all, &var);
	mlx_loop_hook(var.mlx.init, update, &var);
	mlx_loop(var.mlx.init);
	return (free_all(&var), 0);
}
