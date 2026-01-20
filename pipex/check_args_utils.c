/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:54:21 by omawele           #+#    #+#             */
/*   Updated: 2026/01/20 17:57:35 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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

void free_tab(char ***tab)
{
    int i;

    i = 0;
    while ((*tab)[i])
    {
        free((*tab)[i]);
        i++;
    }
    free((*tab));
}

char *create_bin_cmd(char *cmd)
{
    char *bin;

    bin = ft_strjoin("/bin/", cmd);
    if (!bin)
        return (NULL);
    return (bin);
}

char *create_usr_bin_cmd(char *cmd)
{
    char *usr_bin;

    usr_bin = ft_strjoin("/usr/bin/", cmd);
    if (!usr_bin)
        return (NULL);
    return (usr_bin);
}

char **arrange_cmd(char *cmd)
{
    char **tab;

    tab = ft_split(cmd, ' ');
    if (!tab)
        return (NULL);
    return (tab);
}