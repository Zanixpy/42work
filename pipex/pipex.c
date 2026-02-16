/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/02/16 17:05:31 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_error(char *msg)
{
	perror(msg);
}

int	execute_first_cmd(int *fds, char **argv, char **envp)
{
	char	**env;
	char	*cmd;
	int		fd;
	int		ret;

	close(fds[0]);
	if (check_first_file(argv[1]))
		(close(fds[1]), exit(EXIT_FAILURE));
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		(close(fds[1]), print_error(argv[1]), exit(EXIT_FAILURE));
	if (change_stdin_out(fd, fds[1]))
		(print_error("dup"), exit(EXIT_FAILURE));
	cmd = create_cmd(argv[2], envp);
	if (!cmd)
		(print_error(argv[2]), exit(EXIT_FAIL_CMD2));
	env = create_env(cmd, argv[2]);
	if (!env)
		(free(cmd), exit(EXIT_FAIL_CMD2));
	ret = execve(cmd, env, envp);
	free(cmd);
	free_tab(&env);
	if (ret != 0)
		(print_error(argv[2]), exit(EXIT_FAIL_CMD2));
	exit(EXIT_SUCCESS);
}

int	execute_second_cmd(int *fds, char **argv, char **envp)
{
	char	**env;
	char	*cmd;
	int		fd;
	int		ret;

	close(fds[1]);
	if (check_second_file(argv[4]))
		(close(fds[0]), exit(EXIT_FAILURE));
	fd = open(argv[4], O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (fd == -1)
		(close(fds[0]), print_error(argv[4]), exit(EXIT_FAILURE));
	if (change_stdin_out(fds[0], fd))
		(print_error("dup"), exit(EXIT_FAILURE));
	cmd = create_cmd(argv[3], envp);
	if (!cmd)
		(print_error(argv[3]), exit(EXIT_FAIL_CMD2));
	env = create_env(cmd, argv[3]);
	if (!env)
		(free(cmd), exit(EXIT_FAIL_CMD2));
	ret = execve(cmd, env, envp);
	free(cmd);
	free_tab(&env);
	if (ret != 0)
		(print_error(argv[3]), exit(EXIT_FAIL_CMD2));
	exit(EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	pid_t	pid1;
	pid_t	pid2;
	int		status;
	int		fds[2];

	if (args_validation(argc) || pipe(fds) == -1)
		return (EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == -1)
		return (EXIT_FAILURE);
	if (pid1 == 0)
		exit(execute_first_cmd(fds, argv, envp));
	close(fds[1]);
	waitpid(pid1, &status, 0);
	pid2 = fork();
	if (pid2 == -1)
		return (close(fds[0]), EXIT_FAILURE);
	if (pid2 == 0)
		exit(execute_second_cmd(fds, argv, envp));
	close(fds[0]);
	waitpid(pid2, &status, 0);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_SUCCESS);
}
