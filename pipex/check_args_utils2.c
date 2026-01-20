/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_utils2.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:57:11 by omawele           #+#    #+#             */
/*   Updated: 2026/01/20 18:06:42 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execve_cmd(char *bin_cmd, char *usr_bin_cmd, char *argv[], char *envp[])
{
	pid_t	pid;
	int		status;

	pid = fork();
	if (pid == -1)
		return (EXIT_FAILURE);
	else if (pid == 0)
	{
		if (execve(bin_cmd, argv, envp) == -1)
			status = EXIT_FAILURE;
		if (execve(usr_bin_cmd, argv, envp) == -1)
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

int	cmd_one_with_flags(char *argv[], char *envp[])
{
	char	**tab;
	char	*cmd;
	char	*bin_cmd;
	char	*usr_bin_cmd;

	cmd = ft_strtrim(argv[2], " ");
	if (!cmd)
		return (1);
	tab = arrange_cmd(cmd);
	if (!tab)
		return (free(cmd), 1);
	argv[2] = tab[1];
	bin_cmd = create_bin_cmd(tab[0]);
	if (!bin_cmd)
		return (free(cmd), free_tab(&tab), 1);
	usr_bin_cmd = create_usr_bin_cmd(tab[0]);
	if (!usr_bin_cmd)
		return (free(cmd), free_tab(&tab), free(bin_cmd), 1);
	execve_cmd(bin_cmd, usr_bin_cmd, tab, envp);
	return (free(cmd), free(bin_cmd), free(usr_bin_cmd), free_tab(&tab), 0);
}

int	cmd_one_without_flags(char *argv[], char *envp[])
{
	char	*cmd;
	char	*bin_cmd;
	char	*usr_bin_cmd;

	cmd = ft_strtrim(argv[2], " ");
	if (!cmd)
		return (1);
	bin_cmd = create_bin_cmd(cmd);
	if (!bin_cmd)
		return (free(cmd), 1);
	usr_bin_cmd = create_usr_bin_cmd(cmd);
	if (!usr_bin_cmd)
		return (free(cmd), free(bin_cmd), 1);
	execve_cmd(bin_cmd, usr_bin_cmd, argv, envp);
	return (free(cmd), free(bin_cmd), free(usr_bin_cmd), 0);
}
