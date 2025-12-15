/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:32 by omawele           #+#    #+#             */
/*   Updated: 2025/12/15 20:21:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_file(char *s)
{
	int	fd;
	int	size;

	if (!s)
		return (1);
	size = ft_strlen(s);
	if (size < 5)
		return (1);
	if (!(s[size - 1] == 'r' && s[size - 2] == 'e' && s[size - 3] == 'b'
			&& s[size - 4] == '.'))
		return (1);
	fd = open(s, O_RDONLY);
	if (fd < 0)
		return (1);
	return (close(fd), 0);
}

static void	error_check(char c, int n)
{
	write(2, "Error\n", 6);
	if (c == 'f')
		write(2, "Bad file format or file descriptor", 34);
	else if (c == 'm')
	{
		if (n == 0)
			write(2, "Map size is invalid", 19);
		else if (n == 1)
			write(2, "Map characters is invalid", 25);
		else if (n == 2)
			write(2, "No path found in map", 20);
	}
	else if (c == 'c')
		write(2, "Problem with parsing file into tab", 34);
	else if (c == 'b')
		write(2, "Problem on creating the window or charging textures", 51);
}

// int update(t_window *mlx)
// {
//     (void)mlx;
//     return (0);
// }

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
	mlx_loop(var.mlx.init);
	return (free_all(&var), 0);
}
