/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:42:43 by omawele           #+#    #+#             */
/*   Updated: 2025/12/09 13:02:13 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    free_line(t_var *var, int y)
{
    if (y > 0)
    {
        while (--y >= 0)
            free(var->map.map[y]);
    }
    free(var->map.map);
}

static int     count_line(t_var *var, char *filename)
{
    char  *line;
    int fd;
    int count;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    count = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        count++; 
        free(line);
        line = get_next_line(fd);        
    }
    var->map.height = count;
    return (close(fd), count);
}
static int malloc_line(t_var *var, char *line, int y)
{
    int size;
    int x;
    int nul;
    
    if (!line)
        return (0);
    size = ft_strlen(line);
    nul = 1;
    if (ft_strchr(line, '\n'))
        nul = 0;     
    var->map.map[y] = malloc((size + nul) * sizeof(char));
    if (!var->map.map[y])
        return (free_line(var, y), 0);
    x = 0;
    while (x < size)
    {
        var->map.map[y][x] = line[x];
        x++;
    }
    var->map.map[y][(size + nul) - 1] = '\0';
    return (1);
}

int create_map(t_var *var, char *filename)
{
    char *line;
    int fd;
    int y;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);        
    var->map.map = malloc((count_line(var, filename) + 1) * sizeof(char *));
    if (!var->map.map)
        return (close(fd),0);        
    y = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        if(!malloc_line(var, line, y))
            return (free(line), close(fd), 0);
        y++;
        free(line);
        line = get_next_line(fd);        
    }
    return (close(fd), 1);
}
