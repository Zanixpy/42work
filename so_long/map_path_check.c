/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_path_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/06 19:53:50 by omawele           #+#    #+#             */
/*   Updated: 2025/12/08 12:05:41 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"


int   *init_bfs_tab(t_var *var, int **queue_x, int **queue_y)
{
    *queue_x = ft_calloc(var->map.width * var->map.height, sizeof(int));
    if (!(*queue_x))
        return (0);
    *queue_y = ft_calloc(var->map.width * var->map.height, sizeof(int));
    if (!(*queue_y))
    {
        free(*queue_x);
        return (0);
    }
    return (1);
}

int check_adj_wall(t_var *var, char **map, int x, int y)
{
    if (map[y + 1][x] == 0 || map[y - 1][x] == var->map.height - 1)
        return (0);
    if (map[y][x + 1] == 0 || map[y][x - 1] == var->map.width - 1)
        return (0);
    return (1);
}

void   check_map_path(t_var *var, char **map)
{
    int *queue_x;
    int *queue_y;
    int front;
    int back;
    int coins;
    
    if (!init_bfs_tab(var, &queue_x, &queue_y))
        return;
    front = 0;
    back = 0;
    coins = var->cmap.collectible;
    queue_x[back] = var->cmap.p_x;
    queue_y[back] = var->cmap.p_y;
    map[var->cmap.p_y][var->cmap.p_x] = 'T';
    back++;
    
    while (front < back)
    {
        if (queue_x[front])
        
        /* code */
    }
    
    
    var->cmap.valid_path = 1;
    free(queue_x);
    free(queue_y);    
}

