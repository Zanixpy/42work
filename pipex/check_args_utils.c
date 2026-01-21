/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:54:21 by omawele           #+#    #+#             */
/*   Updated: 2026/01/21 11:43:48 by omawele          ###   ########.fr       */
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

char *create_cmd(char *s)
{
	char *tmp;
	char *final;

	tmp = ft_strtrim(s, " ");
	if (!tmp)
		return (NULL);
	final = ft_strjoin("/bin/", tmp);
	if (!final)
		return (free(tmp), NULL);
	return (free(tmp), final);
}



char **create_env(char *cmd, char *flags)
{
    char **tab;
    char **tmp;
    int cw;

    cw = count_words(flags);
    if (cw > 1)
        tmp = ft_split(flags, ' ');
    
    
    
}
