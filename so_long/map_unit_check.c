/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_unit_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:08:24 by omawele           #+#    #+#             */
/*   Updated: 2025/12/06 19:52:12 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

static void set_checker(t_var *var)
{
    var->cmap.collectible = 0;
    var->cmap.player = 0;
    var->cmap.wall = 0;
    var->cmap.space = 0;
    var->cmap.exit_game = 0;
}

static int extract_lines(t_var *var, int fd)
{
    char *s;
    int i;
    int j;

    s = get_next_line(fd);
    if (!s)
    {
        close(fd);
        return (1);        
    }
    i = 0;
    while (s != NULL) 
    {
        j = 0;
        while (*s != '\n' || *s != '\0')
        {
            var->map.map[i][j] = *s;
            j++;
        }
        i++;
        free(s);
        s = get_next_line(fd);
    }
    close(fd);
    return (0);
}

int     is_map_valid(t_var *var, int fd)
{   
    if (extract_lines(var, fd))
        return (1);
    var->map.xsize = check_xsize(var);
    var->map.ysize = check_ysize(var);
    if (var->map.xsize || var->map.ysize)
        return (2);
    set_checker(var);
    if (check_characters(var))
        return (3);
    
    

    return (0);
}





