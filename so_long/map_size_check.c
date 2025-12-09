/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_size_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 17:11:22 by omawele           #+#    #+#             */
/*   Updated: 2025/12/09 13:01:34 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_map_size(t_var *var)
{
    int x;
    int y;
    int cmp;

    y = 0;
    cmp = 0;
    while (var->map.map[y][cmp] != '\0')
        cmp++;
    // ft_printf("cmp : %d\n", cmp);
    // ft_printf("cmp : %d\n", cmp);
    y++;
    while (y < var->map.height)
    {
        x = 0;
        while (var->map.map[y][x] != '\0')
            x++;       
        // ft_printf("x : %d\n", x);
        ft_printf("map : %s\n", var->map.map[y]);
        if (cmp != x)
            return (0);
        y++;
    }
    if (y < 4 || x < 4)
        return (0);
    var->map.width = x; 
    return (1);
}

