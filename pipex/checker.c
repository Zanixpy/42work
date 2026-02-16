/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/02/16 16:40:54 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_first_file(char *filename1)
{
	if (access(filename1, F_OK) == -1 || access(filename1, R_OK) == -1)
	{
		perror(filename1);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	check_second_file(char *filename2)
{
	int	fd2;

	fd2 = open(filename2, O_CREAT | O_WRONLY | O_TRUNC, 00644);
	if (fd2 == -1)
	{
		perror(filename2);
		return (EXIT_FAILURE);
	}
	close(fd2);
	return (EXIT_SUCCESS);
}

int	args_validation(int argc)
{
	if (argc != 5)
	{
		ft_putstr_fd("format: [file1] [cmd1] [cmd2] [file2]\n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
