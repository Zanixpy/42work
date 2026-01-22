/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:02:22 by omawele           #+#    #+#             */
/*   Updated: 2026/01/22 17:00:57 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

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



// char **create_env(char *cmd, char *flags)
// {
//     char **tab;
//     char **tmp;
//     int cw;

//     cw = count_words(flags);
//     if (cw > 1)
//         tmp = ft_split(flags, ' ');   
// }