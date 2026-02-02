/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/02/02 18:47:52 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_errors(int code)
{
	if (code == EXIT_FAILURE)
		ft_putstr_fd("error: fault occured somewhere\n", 2);
	else if (code == EXIT_FAIL_ARGS)
		ft_putstr_fd("args: more or less than 4\n", 2);
	else if (code == EXIT_FAIL_OPEN)
		ft_putstr_fd("open: couldn't open the file\n", 2);
	else if (code == EXIT_FAIL_CMD || code == EXIT_FAIL_CMD2)
		ft_putstr_fd("command: not found\n", 2);
	else if (code == EXIT_FAIL_PERM)
		ft_putstr_fd("file: permission denied for writing or reading\n", 2);
	else if (code == EXIT_FAIL_FORK)
		ft_putstr_fd("fork: an error occured\n", 2);
	else if (code == EXIT_FAIL_PIPE)
		ft_putstr_fd("pipe: an error occured\n", 2);
}

int	pipex(char **argv, char **envp)
{
	int	*fds;
	int	fd1;
	int	fd2;
	int	result_cmd;
	int	result_cmd2;

	fds = create_fds();
	if (!fds)
		return (EXIT_FAILURE);
	if (pipe(fds) == -1)
		return (free(fds), EXIT_FAIL_PIPE);
	fd1 = open_fd(argv[1], O_RDONLY);
	fd2 = open_fd(argv[4], O_WRONLY | O_TRUNC);
	if (fd1 == EXIT_FAIL_OPEN || fd2 == EXIT_FAIL_OPEN)
		return (close_fds(fd1, fd2), free(fds), EXIT_FAIL_OPEN);
	result_cmd = execute_first_cmd(fds, fd1, argv, envp);
	if (result_cmd)
		return (close(fd1), close(fd2), free(fds), result_cmd);
	close(fd1);
	result_cmd2 = execute_second_cmd(fds, fd2, argv, envp);
	if (result_cmd2)
		return (close(fd2), free(fds), result_cmd2);
	return (close(fd2), free(fds), EXIT_SUCCESS);
}

int	main(int argc, char **argv, char **envp)
{
	int	carg;
	int	result;

	if (argc != 5)
		return (print_errors(EXIT_FAIL_ARGS), EXIT_FAIL_ARGS);
	carg = args_validation(argv, envp);
	if (carg == EXIT_FAIL_CMD2)
		return (print_errors(carg), EXIT_FAIL_CMD2);
	else if (carg)
		return (print_errors(carg), EXIT_SUCCESS);
	result = pipex(argv, envp);
	return (print_errors(result), EXIT_SUCCESS);
}
