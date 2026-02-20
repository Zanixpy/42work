/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmds_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/22 16:02:22 by omawele           #+#    #+#             */
/*   Updated: 2026/02/19 15:04:25 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

static char	*separate_cmd_flags(char *s)
{
	char	**tmp;
	char	*final;

	tmp = ft_split(s, ' ');
	if (!tmp)
		return (NULL);
	final = ft_strdup(tmp[0]);
	if (!final)
		return (free_tab(&tmp), NULL);
	return (free_tab(&tmp), final);
}

char	*create_cmd(char *cmd, char **env)
{
	char	*tmp;
	char	*tmp2;
	char	*final;

	tmp2 = NULL;
	tmp = ft_strtrim(cmd, " ");
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
	final = find_path(tmp, env);
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
		{
			print_error(cmd);
			exit(EXIT_FAIL_CMD2);
		}
		exit(0);
	}
	waitpid(pid, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_SUCCESS);
}

char **create_env(char *cmd, char *original_cmd)
{
	char **env;

	if (count_words(original_cmd) > 1)
		env = create_env_with_flags(cmd, original_cmd);
	else
	 	env = create_env_without_flags(cmd);
	if (!env)
		return (NULL);
	return (env);
}


