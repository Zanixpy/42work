/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_file.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/05 18:08:24 by omawele           #+#    #+#             */
/*   Updated: 2025/12/05 18:38:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "get_next_line.h"
#include <string.h>

int     parsing_map(t_var *var, char *file)
{
    int fd;
    int round; 
    char *s;

    fd = open("map.ber", O_RDONLY);
    if (fd < -1)
        return (1); 
    s = get_next_line(fd);
    while (s != NULL) 
    {
        
    }
    
}

int check_first_last_line(t_var *var, char *s)
{
    char wall;

    wall = '1';
    while (*s != '\n' || *s != '\0') 
    {
        if (*s != wall)
        {
            var->mp.wall = 0;
            return (1);
        }
        s++;
    }
    return (0);   
}

int check_middle_line(t_var *var, char *s)
{
    char wall;
    char player;
    char collectible;
    char exit;
    char space;
    
    wall = '1';
    space = '0';
    collectible = 'C';
    exit = 'E';
    player = 'P';
    while (*s != '\n' || *s != '\0') 
    {
        if (*s == )
            return (1);
        s++;
    }
    return (0); 
    
}


