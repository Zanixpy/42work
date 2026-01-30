/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:28:16 by omawele           #+#    #+#             */
/*   Updated: 2026/01/30 13:17:39 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char *find_path(char *cmd, char **env)
{
    char **tab;
    char *bin;
    char *usr_bin;
    char *path;
    char *final;

    path = get_path(env);
    if (!path)
        return (NULL);
    tab = ft_split(path, ':');
    if (!tab)
        return (free(path), NULL);
    bin = ft_strjoin("/bin/", cmd);
    if (!bin)
        return (free(path), free_tab(&tab), NULL);
    usr_bin = ft_strjoin("/usr/bin/", cmd);
    if (!usr_bin)
        return (free(path), free_tab(&tab), free(bin), NULL);
    if (access(bin, F_OK) == 0)
		return (free(path), free_tab(&tab), free(usr_bin), bin);
    else if (access(usr_bin, F_OK) == 0)
		return (free(path), free_tab(&tab), free(bin), usr_bin);
    final = search_path(tab, cmd);
    return (free(path), free_tab(&tab), free(bin), free(usr_bin), final);
}

char *get_path(char **env)
{
    int i;
    char *path;
    char *sub_path;

    i = 0;
    path = NULL;
    while (env[i]) 
    {
        if (ft_strnstr(env[i], "PATH=", 5))
        {
            path = ft_strdup(env[i]);
            if (!path)
                return (NULL);
            break;
        }
        i++;
    }
    if (!path)
        return (NULL);
    sub_path = ft_substr(path, 5, ft_strlen(path));
    if (!sub_path)
        return (free(path), NULL);
    return (free(path), sub_path);
}

char *search_path(char **path, char *cmd)
{
    int i;
    char *final;

    i = 0;
    final = NULL;
    while (path[i]) 
    {
        final = ft_strjoin(path[i], cmd);
        if (!final)
            return (NULL);
        if (access(final, F_OK) == 0)
            break;
        i++;
        free(final);
        final = NULL;
    }
    return (final);   
}
