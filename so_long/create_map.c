/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:42:43 by omawele           #+#    #+#             */
/*   Updated: 2025/12/08 10:40:10 by omawele          ###   ########.fr       */
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

static int     count_line(char *filename)
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
    return (close(fd), count);
}
static int malloc_line(t_var *var, char *line, int y)
{
    int size;
    int x;
    
    size = ft_strlen(line);
    if (!size)
        return (0);
    var->map.map[y] = ft_calloc(size, sizeof(char));
    if (!var->map.map[y])
        return (free_line(var, y), 0);
    if (ft_strchr(line, '\n'))
        size -= 1;
    x = 0;
    while (x < size)
    {
        var->map.map[y][x] = line[x];
        x++;
    }
    return (1);
}

int create_map(t_var *var, char *filename)
{
    char **tab;
    char *line;
    int fd;
    int y;

    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (0);
    tab = ft_calloc(count_line(filename) + 1, sizeof(char *));
    if (!tab)
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
