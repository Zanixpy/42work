/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/23 12:47:19 by omawele           #+#    #+#             */
/*   Updated: 2026/01/29 14:25:37 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	execute_first_cmd(int *fds, int fd1, char **argv, char **envp)
{
	char	**env;
	char	*cmd;
	int		save_stdin;
	int		save_stdout;

	cmd = create_cmd(argv[2]);
	if (!cmd)
		return (EXIT_FAILURE);
	if (count_words(argv[2]) > 1)
		env = create_env_with_flags(cmd, argv[2]);
	else
		env = create_env_without_flags(cmd);
	if (!env)
		return (free(cmd), EXIT_FAILURE);
	save_stdin = change_stdin_out(STDIN_FILENO, fd1);
	save_stdout = change_stdin_out(STDOUT_FILENO, fds[1]);
	if (execve_cmd(cmd, env, envp) == EXIT_FAILURE)
	{
		restore_stdin_out(save_stdin, STDIN_FILENO);
		restore_stdin_out(save_stdout, STDOUT_FILENO);
		return (free(cmd), free_tab(&env), EXIT_FAIL_FORK);
	}
	restore_stdin_out(save_stdin, STDIN_FILENO);
	restore_stdin_out(save_stdout, STDOUT_FILENO);
	return (free(cmd), free_tab(&env), EXIT_SUCCESS);
}

int	execute_second_cmd(int *fds, int fd2, char **argv, char **envp)
{
	char	**env;
	char	*cmd;
	int		save_stdin;
	int		save_stdout;

	cmd = create_cmd(argv[3]);
	if (!cmd)
		return (EXIT_FAILURE);
	if (count_words(argv[3]) > 1)
		env = create_env_with_flags(cmd, argv[3]);
	else
		env = create_env_without_flags(cmd);
	if (!env)
		return (free(cmd), EXIT_FAILURE);
	save_stdin = change_stdin_out(STDIN_FILENO, fds[0]);
	save_stdout = change_stdin_out(STDOUT_FILENO, fd2);
	if (execve_cmd(cmd, env, envp) == EXIT_FAILURE)
	{
		restore_stdin_out(save_stdin, STDIN_FILENO);
		restore_stdin_out(save_stdout, STDOUT_FILENO);
		return (free(cmd), free_tab(&env), EXIT_FAIL_FORK);
	}
	restore_stdin_out(save_stdin, STDIN_FILENO);
	restore_stdin_out(save_stdout, STDOUT_FILENO);
	return (free(cmd), free_tab(&env), EXIT_SUCCESS);
}
