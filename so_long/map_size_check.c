/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:11:22 by omawele           #+#    #+#             */
/*   Updated: 2025/12/08 10:42:06 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_size(t_var *var)
{
    int x;
    int y;

    y = 0;
    x = line_size(var, y);
    if (x < 4)
        return (0);
    while (var->map.map[y][0])
    {
        y++;
        if (x != line_size(var, y))
            return (1);
    }
    if (y < 4)
        return (0);
    var->map.width = x; 
    var->map.height = y;
    return (1);
}

static int xline_size(t_var *var, int y)
{
    int x;
    
    x = 0;
    while (!var->map.map[y][x])
    {
        x++;
    }
    return (x);
}