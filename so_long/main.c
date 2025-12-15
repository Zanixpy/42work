/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 17:01:32 by omawele           #+#    #+#             */
/*   Updated: 2025/12/15 17:43:33 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int check_file(char *s)
{
    int fd;
    int size;

    if (!s)
        return (0);
    size = ft_strlen(s);
    if (size < 5)
        return (1);
    if (!(s[size - 1] == 'r' && s[size - 2] == 'e' && s[size - 1] == 'b' && s[size - 1] == '.'))
        return (1);
    fd = open(s, O_RDONLY);
    if (fd < 0)
        return (2);
    return (close(fd), 0);
}

static void error_check(char c, int n)
{
    write(2, "Error\n", 6);
    if (c == 'f')
    {
        if (n == 1)
            write(2, "Bad file format", 15);
        else if (n == 2)
            write(2, "Bad file descriptor", 19);        
    }
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
        write(2, "Problem on opening file", 21);
    else if (c == 'b')
    {
        if (n == 1)
            write(2, "Problem on creating the window", 30);
        else if (n == 2)
            write(2, "Problem with textures", 21);
    }
}

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
    if (!check_file(argv[1]))
        return (0);   
    var.map.map = create_map(&var ,argv[1]);
    if (!var.map.map)
        return ( 1);
    var.cpath.tmap = create_map(&var ,argv[1]);
    if (!var.cpath.tmap)
        return (free_tab(&var.map.map, var.map.height), 1);
    result = is_map_valid(&var);
    if (result)

	mlx_hook(var.mlx.win, 2, 1L<<0, handleKey, &var);
	mlx_hook(var.mlx.win, 17, 0, free_all, &var);
    mlx_loop_hook(var.mlx.init, update, &var);
    mlx_loop(var.mlx.init);
    free_all(&var);
    return (0);
}
