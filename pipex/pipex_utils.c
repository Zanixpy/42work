/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:47:19 by omawele           #+#    #+#             */
/*   Updated: 2026/01/23 15:56:55 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "pipex.h"
#include <cstdlib>
#include <string.h>

int build_first_cmd_env(int *fds, char **argv, char **envp)
{
    char **env;
    char *cmd;

    cmd = create_cmd(argv[2]);
    if (!cmd)
        return (EXIT_FAILURE);
    if (count_words(argv[2]) > 1)
        env = create_env_with_flags(cmd, argv[2], argv[1]);
    else
        env = create_env_without_flags(cmd, argv[1]);
    if (!env)
        return (free(cmd), EXIT_FAILURE);

    return (free(cmd), free_tab(&env), EXIT_SUCCESS);
    
    
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

int execute_first_cmd(int *fds, char **argv, char **envp)
{
    char **env;
    char *cmd;

    cmd = create_cmd(argv[2]);
    if (!cmd)
        return (EXIT_FAILURE);
    
    
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
    char *tmp;

    tab = ft_calloc(3, sizeof(char *));
    if (!tab)
        return (NULL);
    tab[0] = cmd;
    tab[1] = filename1;
    return (tab);
}
