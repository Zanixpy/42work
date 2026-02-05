/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 18:22:14 by omawele           #+#    #+#             */
/*   Updated: 2026/02/05 12:46:13 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	check_first_file(char *filename1)
{
	if (access(filename1, R_OK) == -1)
		return (EXIT_FAIL_FIRST_FILE);
	return (EXIT_SUCCESS);
}

int	check_second_file(char *filename2)
{
	int	fd2;

	fd2 = open(filename2, O_WRONLY | O_TRUNC);
	if (fd2 > 2)
	{
		if (access(filename2, W_OK) == -1 || access(filename2, R_OK) == -1)
			return (close(fd2), EXIT_FAIL_SEC_FILE);
		return (close(fd2), EXIT_SUCCESS);	
	}
	fd2 = open(filename2, O_CREAT , 00644);
	if (fd2 != -1)
		return (close(fd2), EXIT_FAIL_SEC_FILE);
	return (close(fd2), EXIT_SUCCESS);
}

