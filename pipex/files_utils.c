/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:54:21 by omawele           #+#    #+#             */
/*   Updated: 2026/01/22 16:45:06 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int *create_fds(char *filename1, char *filename2, int mode1, int mode2)
{
	int *fds;
	int fd1;
	int fd2;

	fd1 = open_fd(filename1, mode1);
    fd2 = open_fd(filename2, mode2);
    if (fd1 == EXIT_FAIL_OPEN || fd2 == EXIT_FAIL_OPEN)
	{
        return (close_fds(fd1, fd2), NULL);
	}
	fds = malloc(2 * sizeof(int));
	if (!fds)
		return (close_fds(fd1, fd2), NULL);
	fds[0] = fd1;
	fds[1] = fd2;
	return (fds);
}

int open_fd(char *filename, int mode)
{
	int fd;

	fd = open(filename, mode);
	if (fd == -1)
		return (EXIT_FAIL_OPEN);
	return (fd);
}

void close_fds(int fd1, int fd2)
{
	if (fd1 > 2)
		close(fd1);
	if (fd2 > 2)
		close (fd2);
}


