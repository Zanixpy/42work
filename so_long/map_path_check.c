/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:53:50 by omawele           #+#    #+#             */
/*   Updated: 2025/12/12 15:01:56 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void path_search(char ***tab, int x, int y)
{    
    if ((*tab)[y][x] == '1' || (*tab)[y][x] == 'T')
        return;
    (*tab)[y][x] = 'T';
    path_search(tab, x, y + 1);            
    path_search(tab, x, y - 1);        
    path_search(tab, x + 1, y);        
    path_search(tab, x - 1, y);   
}

void   check_map_path(t_var *var)
{
    int y;
    int x;
    
    path_search(&(var->cpath.tmap), var->p.pos_x_map, var->p.pos_y_map);
    y = 1;
    while (y < var->map.height)
    {
        x = 1;
        while (x < var->map.width - 1)
        {
            if (var->cpath.tmap[y][x] == 'C' \
                ||  var->cpath.tmap[y][x] == 'E' \
                || var->cpath.tmap[y][x] == 'P')
                return;
            x++;
        }
        y++;
    }
    var->cpath.valid_path = 1;
}

