/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_characters_check.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 18:13:13 by omawele           #+#    #+#             */
/*   Updated: 2025/12/09 10:55:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int is_wscep(t_var *var, int x, int y)
{
    if ((x == 0 || x == var->map.width - 1) && var->map.map[y][x] != '1')
        return (0);
    if ((y == 0 || y == var->map.height - 1) && var->map.map[y][x] != '1')
        return (0);
    if (var->map.map[y][x] == 'P' && !var->cmap.player)
    {
        var->cmap.player = 1;
        var->p.pos_x = x;
        var->p.pos_y = y;        
    }
    else if (var->map.map[y][x] == 'E' && !var->cmap.exit_game)
        var->cmap.exit_game = 1;
    else if (var->map.map[y][x] == 'C')
        var->cmap.collectible += 1;
    else if (var->map.map[y][x] == 'S')
        var->cmap.space = 1;
    else     
        return (0);
    return (1);
}

static void check_wall(t_var *var)
{
    int x;
    int y;
    char **map;

    map = var->map.map;
    x = 0;
    y = 0;
    while (map[0][x] == '1' && map[0][x] == '1' && x < var->map.width)
        x++;
    if (x != var->map.width)
        return;
    while (map[y][0] == '1' && map[y][x - 1] == '1' && y < var->map.height)
        y++;
    if (y != var->map.height)
        return;
    var->cmap.wall = 1; 
}

static int check_characters_errors(t_var *var)
{
    if (!var->cmap.wall)
        return (0);
    if (!var->cmap.collectible)
        return (0);
    if (!var->cmap.exit_game)
        return (0);
    if (!var->cmap.space)
        return (0);
    if (!var->cmap.player)
        return (0);   
    return (1);
}

int check_map_characters(t_var *var)
{
    int x;
    int y;

    y = 1;
    while (y < var->map.height - 1)
    {
        x = 1;
        while (x < var->map.width - 1)
        {
            if (!is_wscep(var, x, y))
                return (0);
            x++;
        }
        y++;
    }
    check_wall(var);
    return (check_characters_errors(var));
}




