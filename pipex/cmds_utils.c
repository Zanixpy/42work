/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:02:22 by omawele           #+#    #+#             */
/*   Updated: 2026/01/26 16:49:50 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <cstdlib>
#include <string.h>

char *separate_cmd_flags(char *s)
{
	char **tmp;
	char *final;

	tmp = ft_split(s, ' ');
	if (!tmp)
		return (NULL);
	final = ft_strdup(tmp[0]);
	if (!final)
		return (free_tab(&tmp), NULL);
	return (free_tab(&tmp), final);
}

char *create_cmd(char *s)
{
	char *tmp;
    char *tmp2;
	char *final;

    tmp2 = NULL;
	tmp = ft_strtrim(s, " ");
	if (!tmp)
		return (NULL);
    if (count_words(tmp) > 1)
    {
        tmp2 = separate_cmd_flags(tmp);
        free(tmp);
        if (!tmp2)
            return (NULL);
        tmp = tmp2;
    }
	final = ft_strjoin("/bin/", tmp);
	if (!final)
		return (free(tmp), NULL);
	return (free(tmp), final);
}

int	execve_cmd(char *cmd, char *argv[], char *envp[])
{
	pid_t	pid;
	int		status;

	pid = fork();
    status = 0;
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
	{
		if (execve(cmd, argv, envp) == -1)
			status = EXIT_FAILURE;
		exit(status);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status))
		{
			if (WEXITSTATUS(status) == EXIT_FAILURE)
				return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}

char **create_env_with_flags(char *cmd, char *original_cmd, char *filename1)
{
    char **tab;
    char **tab_tmp;
    char *tmp;
    int size_flags;

    tmp = ft_strtrim(original_cmd, " ");
    if (!tmp)
        return (NULL);
    tab_tmp = ft_split(tmp, ' ');
    if (!tab_tmp)
        return (free(tmp), NULL);
    size_flags = 0;
    while (tab_tmp[size_flags]) 
        size_flags++;
    tab = create_tab_with_flags(cmd, tab_tmp, filename1, size_flags - 1);
    if (!tab)
        return (free(tmp), free_tab(&tab_tmp), NULL);
    return (free(tmp), free_tab(&tab_tmp), tab);   
}

char **create_env_without_flags(char *cmd, char *filename1)
{
    char **tab;

    tab = ft_calloc(3, sizeof(char *));
    if (!tab)
        return (NULL);
    tab[0] = ft_strdup(cmd);
	if (!(tab[0]))
		return (free(tab), NULL);
    tab[1] = ft_strdup(filename1);
	if (!(tab[1]))
		return (free(tab[0]), free(tab), NULL);
    return (tab);
}
