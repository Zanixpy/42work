/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:53:50 by omawele           #+#    #+#             */
/*   Updated: 2025/12/09 10:56:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


static void path_search(t_var *var, int x, int y, char **map)
{    
    if (x < 0 || x >= var->map.width || y < 0 || y >= var->map.height \
        || map[y][x] == '1')
        return;
    if (map[y][x] == 'C')
    {
        var->cpath.collectible += 1;
        map[y][x] = '0';
    }
    else if (map[y][x] == 'E')
        var->cpath.exit_game = 1;
    path_search(var, x + 1, y, map);
    path_search(var, x - 1, y, map);    
    path_search(var, x, y + 1, map);    
    path_search(var, x, y - 1, map);    
}

void   check_map_path(t_var *var)
{
    path_search(var, var->p.pos_x, var->p.pos_y, var->map.map);
    if ((var->cpath.collectible == var->cmap.collectible) \
        && var->cpath.exit_game)
        var->cpath.valid_path = 1;
}

