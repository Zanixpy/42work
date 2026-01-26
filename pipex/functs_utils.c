/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functs_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:05:57 by omawele           #+#    #+#             */
/*   Updated: 2026/01/26 16:59:07 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <stdlib.h>
#include <string.h>

int count_words(char *s)
{
    int count;
    int start_word;

    count = 0;
    start_word = 0;

    while (*s)
    {
        if (*s != ' ' && start_word == 0)
        {
            count++;
            start_word = 1;
        }
        else if (*s == ' ')
            start_word = 0;
        s++;
    }
    return (count);
}

char **create_tab_with_flags(char *cmd, char **flags, char *filename, int size_flags)
{
    char **tab;
    int  size;
    int i;

    size = size_flags + 3;
    tab = ft_calloc(size, sizeof(char *));
    if (!tab)
        return (NULL);
    i = 0;
    tab[0] = ft_strdup(cmd);
    if (!(tab[0]))
        return (free(tab), NULL);
    while (i++ < size_flags) 
    {
        tab[i] = ft_strdup(flags[i]);
        if (!(tab[i]))
            return (free_tab(&tab), NULL);
    }
    tab[size - 1] = ft_strdup(filename);
    if (!(tab[size - 1]))
        return (free_tab(&tab), NULL);
    return (tab);
}

// char **malloc_tab()
