/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:13:24 by omawele           #+#    #+#             */
/*   Updated: 2026/02/03 16:02:16 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_errors(int code, char *error_name)
{
	if (!error_name)
		return ;
	if (code == EXIT_FAIL_PERM2 || code == EXIT_FAIL_CMD2)
	{
		ft_putstr_fd(error_name, 2);
		if (code == EXIT_FAIL_PERM2)
			ft_putstr_fd(": permission denied\n", 2);
		else
			ft_putstr_fd(": command: not found\n", 2);
		return ;
	}
	ft_putstr_fd(error_name, 1);
	if (code == EXIT_FAILURE)
		ft_putstr_fd(": fault occured somewhere\n", 1);
	else if (code == EXIT_FAIL_ARGS)
		ft_putstr_fd(": more or less than 4\n", 1);
	else if (code == EXIT_FAIL_OPEN)
		ft_putstr_fd(": couldn't open the file\n", 1);
	else if (code == EXIT_FAIL_CMD)
		ft_putstr_fd(": command: not found\n", 1);
	else if (code == EXIT_FAIL_PERM)
		ft_putstr_fd(": permission denied\n", 1);
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
		return (print_errors(EXIT_FAIL_ARGS, "args"), EXIT_SUCCESS);
	carg = args_validation(argv, envp);
	if (carg == EXIT_FAIL_PERM2)
		return (print_errors(carg, argv[4]), EXIT_FAIL_PERM2);
	else if (carg == EXIT_FAIL_CMD2)
		return (print_errors(carg, argv[3]), EXIT_FAIL_CMD2);
	else if (carg == EXIT_FAIL_PERM)
		return (print_errors(carg, argv[1]), EXIT_SUCCESS);
	else if (carg == EXIT_FAIL_CMD)
		return (print_errors(carg, argv[2]), EXIT_SUCCESS);
	else if (carg)
		return (print_errors(carg, "error"), EXIT_SUCCESS);
	result = pipex(argv, envp);
	return (print_errors(result, NULL), EXIT_SUCCESS);
}
