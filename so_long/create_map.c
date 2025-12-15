/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/08 09:42:43 by omawele           #+#    #+#             */
/*   Updated: 2025/12/15 17:44:48 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
static int malloc_line(char ***tab, char **line, int y)
{
    int size;
    int x;
    int nul;
    
    if (!(*line))
        return (free_tab(tab, y), 0);
    size = ft_strlen((*line));
    nul = 1;
    if (ft_strchr((*line), '\n'))
        nul = 0;     
    (*tab)[y] = malloc((size + nul) * sizeof(char));
    if (!(*tab)[y])
        return (free(*line), free_tab(tab, y), 0);
    x = 0;
    while (x < size)
    {
        (*tab)[y][x] = (*line)[x];
        x++;
    }
    (*tab)[y][(size + nul) - 1] = '\0';
    return (1);
}

char **create_map(t_var *var, char *filename)
{
    char **tab;
    char *line;
    int fd;
    int size;
    int y;
    
    fd = open(filename, O_RDONLY);
    if (fd < 0)
        return (NULL);
    size =  count_line(var, filename) + 1;
    if (size == 1)
        return (close(fd), NULL);
    tab = malloc(size * sizeof(char *));
    if (!tab)
        return (close(fd), NULL);        
    y = 0;
    line = get_next_line(fd);
    while (line != NULL)
    {
        if(!malloc_line(&tab, &line, y))
            return (close(fd), NULL);
        y++;
        free(line);
        line = get_next_line(fd);        
    }
    tab[size - 1] = NULL;
    return (close(fd), tab);
}

int init_map(t_var *var, char *filename)
{
    
}
