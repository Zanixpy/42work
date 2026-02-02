/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/02/02 18:42:09 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_first_file(char *filename1)
{
	int	fd1;

	fd1 = open(filename1, O_RDONLY);
	if (fd1 == -1)
		return (EXIT_FAIL_OPEN);
	if (access(filename1, R_OK) == -1)
		return (close(fd1), EXIT_FAIL_PERM);
	return (close(fd1), EXIT_SUCCESS);
}

int	check_second_file(char *filename2)
{
	int	fd2;

	fd2 = open(filename2, O_WRONLY | O_TRUNC);
	if (fd2 > 2)
	{
		if (access(filename2, W_OK) == -1)
			return (close(fd2), EXIT_FAIL_PERM);
		return (close(fd2), EXIT_SUCCESS);
	}
	fd2 = open(filename2, O_CREAT, 00200);
	if (fd2 == -1)
		return (EXIT_FAIL_OPEN);
	return (close(fd2), EXIT_SUCCESS);
}

int	check_cmds(char *cmdname1, char *cmdname2, char **env)
{
	char	*cmd1;
	char	*cmd2;

	cmd1 = create_cmd(cmdname1, env);
	if (!cmd1)
		return (EXIT_FAIL_CMD);
	cmd2 = create_cmd(cmdname2, env);
	if (!cmd2)
		return (free(cmd1), EXIT_FAIL_CMD2);
	return (free(cmd1), free(cmd2), EXIT_SUCCESS);
}

int	args_validation(char **argv, char **env)
{
	int	result;

	result = check_first_file(argv[1]);
	if (result == EXIT_FAIL_OPEN)
		return (EXIT_FAIL_OPEN);
	else if (result == EXIT_FAIL_PERM)
		return (EXIT_FAIL_PERM);
	result = check_second_file(argv[4]);
	if (result == EXIT_FAIL_OPEN)
		return (EXIT_FAIL_OPEN);
	else if (result == EXIT_FAIL_PERM)
		return (EXIT_FAIL_PERM);
	result = check_cmds(argv[2], argv[3], env);
	if (result == EXIT_FAIL_CMD)
		return (EXIT_FAIL_CMD);
	else if (result == EXIT_FAIL_CMD2)
		return (EXIT_FAIL_CMD2);
	return (EXIT_SUCCESS);
}
