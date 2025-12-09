/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:53:50 by omawele           #+#    #+#             */
/*   Updated: 2025/12/09 17:39:14 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void path_search(t_var *var, int x, int y, char **map)
{    
    if (x < 0 || x >= var->map.width || y < 0 || y >= var->map.height \
        || map[y][x] == '1')
        return;
    else 
    {
        map[y][x] = 'T';
        path_search(var, x, y + 1, map);            
        path_search(var, x, y - 1, map);        
        path_search(var, x + 1, y, map);        
        path_search(var, x - 1, y, map);   
    }
}
static int check_player_exit(t_var *var)
{
    int x;
    int y;
    int xe;
    int ye;

    x = var->p.pos_x;
    y = var->p.pos_y;
    xe = var->map.exit_x;
    ye = var->map.exit_y;
    if (var->map.map[y + 1][x] == '1' && var->map.map[y - 1][x] == '1' \
        && var->map.map[y][x + 1] == '1' && var->map.map[y][x - 1] == '1')
        return (0);
    if (var->map.map[ye + 1][xe] == '1' && var->map.map[ye - 1][xe] == '1' \
        && var->map.map[ye][xe + 1] == '1' && var->map.map[ye][xe - 1] == '1')
        return (0); 
    return (1);
}

void   check_map_path(t_var *var)
{
    if (!check_player_exit(var))
        return;
    path_search(var, var->p.pos_x, var->p.pos_y, var->map.map);
    if ((var->cpath.collectible == var->cmap.collectible) \
        && var->cpath.exit_game)
        var->cpath.valid_path = 1;
}

