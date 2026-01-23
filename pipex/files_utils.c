/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:54:21 by omawele           #+#    #+#             */
/*   Updated: 2026/01/23 11:42:21 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int *create_fds(void)
{
	int *fds;

	fds = malloc(2 * sizeof(int));
	if (!fds)
		return (NULL);
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


