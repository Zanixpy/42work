/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/02/04 16:26:56 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_first_file(char *filename1)
{
	if (access(filename1, R_OK) == -1)
		return (EXIT_FAIL_PERM);
	return (EXIT_SUCCESS);
}

int	check_second_file(char *filename2)
{
	int	fd2;

	fd2 = open(filename2, O_WRONLY | O_TRUNC);
	if (fd2 > 2)
	{
		if (access(filename2, W_OK) == -1 || access(filename2, R_OK) == -1)
			return (close(fd2), EXIT_FAIL_PERM2);
		return (close(fd2), EXIT_SUCCESS);	
	}
	fd2 = open(filename2, O_CREAT , 00644);
	if (fd2 != -1)
		return (close(fd2), EXIT_FAIL_OPEN);
	return (close(fd2), EXIT_SUCCESS);
}

int	args_validation(int argc, char **argv, char **env)
{
	int	result;

	(void)env;
	if (argc != 5)
		return (EXIT_FAIL_ARGS);
	result = check_first_file(argv[1]);
	if (result)
		return (result);
	result = check_second_file(argv[4]);
	if (result)
		return (result);
	return (EXIT_SUCCESS);
}
