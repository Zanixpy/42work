/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/02/05 11:48:45 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>

void	print_errors()
{
	perror("error");
}

// int	pipex(char **argv, char **envp)
// {
// 	int	*fds;
// 	int	fd1;
// 	int	fd2;
// 	int	result_cmd;
// 	int	result_cmd2;

// 	fds = create_fds();
// 	if (!fds)
// 		return (EXIT_FAILURE);
// 	if (pipe(fds) == -1)
// 		return (free(fds), EXIT_FAIL_PIPE);
// 	fd1 = open_fd(argv[1], O_RDONLY);
// 	fd2 = open_fd(argv[4], O_WRONLY | O_TRUNC);
// 	if (fd1 == EXIT_FAIL_OPEN || fd2 == EXIT_FAIL_OPEN)
// 		return (close_fds(fd1, fd2), free(fds), EXIT_FAIL_OPEN);
// 	result_cmd = execute_first_cmd(fds, fd1, argv, envp);
// 	if (result_cmd)
// 		return (close(fd1), close(fd2), free(fds), result_cmd);
// 	close(fd1);
// 	result_cmd2 = execute_second_cmd(fds, fd2, argv, envp);
// 	if (result_cmd2)
// 		return (close(fd2), free(fds), result_cmd2);
// 	return (close(fd2), free(fds), EXIT_SUCCESS);
// }

int change_stdin_out_fchild(int *fds, int fd)
{
	close(fds[0]);
	if (dup2(fds[1], STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	close(fds[1]);
	if (dup2(fd, STDIN_FILENO) == -1)
		return (EXIT_FAILURE);
	close(fd);
	return (EXIT_SUCCESS);
}

int change_stdin_out_schild(int *fds, int fd)
{
	close(fds[1]);
	if (dup2(fd, STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	close(fd);
	if (dup2(fds[0], STDIN_FILENO) == -1)
		return (EXIT_FAILURE);
	close(fds[0]);
	return (EXIT_SUCCESS);
}

int launch_first_child(int *fds, char **argv, char **envp)
{
	char	**env;
	char	*cmd;
	int 	fd1;

	fd1 = open_fd(argv[1], O_RDONLY);
	if (fd1 == -1)
		exit(EXIT_FAILURE);
	if (change_stdin_out_fchild(fds, fd1) == -1)
		exit(EXIT_FAILURE);
	cmd = create_cmd(argv[2], envp);
	env = create_env(cmd, argv[2]);
	ft_putstr_fd(env[1], 2);
	if (!cmd || !env)
	{
		free_malloc(&cmd, &env);
		exit(EXIT_FAILURE);
	}
	if (execve_cmd(cmd, env, envp) == EXIT_FAILURE)
	{
		free_malloc(&cmd, &env);
		exit(EXIT_FAILURE);		
	}
}

int launch_second_child(int *fds, char **argv, char **envp)
{
	char	**env;
	char	*cmd;
	int 	fd2;

	fd2 = open_fd(argv[4], O_WRONLY | O_TRUNC);
	if (fd2 == -1)
		exit(EXIT_FAILURE);
	if (change_stdin_out_fchild(fds, fd2) == -1)
		exit(EXIT_FAILURE);
	cmd = create_cmd(argv[4], envp);
	env = create_env(cmd, argv[4]);
	if (!cmd || !env)
	{
		free_malloc(&cmd, &env);
		exit(EXIT_FAILURE);
	}
	if (execve_cmd(cmd, env, envp) == EXIT_FAILURE)
	{
		free_malloc(&cmd, &env);
		exit(EXIT_FAILURE);		
	}
}

int create_pipe(int **fds)
{
	*fds = create_fds();
	if (!(*fds))
		return (EXIT_FAILURE);
	if (pipe(*fds) == -1)
	{
		perror("pipe");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);	
}


int	main(int argc, char **argv, char **envp)
{
	int	carg;
	pid_t pid1;
	pid_t pid2;
	int status;
	int	*fds;

	carg = args_validation(argc, argv, envp);
	if (carg)
		return (print_errors(), EXIT_FAIL_PERM2);
	if (create_pipe(&fds))
		return (EXIT_FAILURE);
	pid1 = fork();
	if (pid1 == 0)
		launch_first_child(fds, argv, envp);
	waitpid(pid1, &status, 0);
	exit(1);
	pid2 = fork();
	if (pid2 == 0)
		launch_second_child(fds, argv, envp);
	waitpid(pid2, &status, 0);
	close(fds[0]);
	close(fds[1]);
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	return (EXIT_SUCCESS);
}
