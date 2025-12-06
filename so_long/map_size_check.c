/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:11:22 by omawele           #+#    #+#             */
/*   Updated: 2025/12/06 19:49:33 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_xsize(t_var *var)
{
    int size;
    int x;

    x = 0;
    size = line_size(var, x);
    if (size < 4)
        return (1);
    while (!var->map.map[x][0] )
    {
        x++;
        if (size != line_size(var, x))
            return (1);
    }
    return (size);
}

int check_ysize(t_var *var)
{
    int size;
    int y;

    y = 0;
    while (!var->map.map[y][0])
    {
        y++;
    }
    if (y < 4)
        return (1);
    return (y);
}

static int xline_size(t_var *var, int x)
{
    int y;
    
    y = 0;
    while (!var->map.map[x][y])
    {
        y++;
    }
    return (y);
}