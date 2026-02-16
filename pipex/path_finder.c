/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/30 12:28:16 by omawele           #+#    #+#             */
/*   Updated: 2026/02/16 01:35:20 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_path(char *cmd, char **env)
{
	char	**tab;
	char	*path;
	char	*final;

	path = get_path(env);
	if (!path)
		return (NULL);
	tab = ft_split(path, ':');
	if (!tab)
		return (free(path), NULL);
	final = search_path(tab, cmd);
	return (free(path), free_tab(&tab), final);
}

char	*get_path(char **env)
{
	int		i;
	char	*path;
	char	*sub_path;

	i = 0;
	path = NULL;
	while (env[i])
	{
		if (ft_strnstr(env[i], "PATH=", 5))
		{
			path = ft_strdup(env[i]);
			if (!path)
				return (NULL);
			break ;
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

char	*search_path(char **path, char *cmd)
{
	int		i;
	char	*final;
	char	*tmp;

	i = 0;
	final = NULL;
	while (path[i])
	{
		tmp = ft_strjoin(path[i], "/");
		if (!tmp)
			return (NULL);
		final = ft_strjoin(tmp, cmd);
		free(tmp);
		if (!final)
			return (NULL);
		if (access(final, F_OK) == 0)
			break ;
		i++;
		free(final);
		final = NULL;
	}
	return (final);
}
