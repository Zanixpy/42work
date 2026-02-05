/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   files_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/20 17:54:21 by omawele           #+#    #+#             */
/*   Updated: 2026/02/04 13:12:40 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	*create_fds(void)
{
	int	*fds;

	fds = malloc(2 * sizeof(int));
	if (!fds)
		return (NULL);
	return (fds);
}

int	open_fd(char *filename, int mode)
{
	int	fd;

	fd = open(filename, mode);
	if (fd == -1)
		return (-1);
	return (fd);
}

void	close_fds(int fd1, int fd2)
{
	if (fd1 > -1)
		close(fd1);
	if (fd2 > -1)
		close(fd2);
}

int	change_stdin_out(int std_fd, int fd)
{
	int	save_std_fd;

	save_std_fd = dup(std_fd);
	dup2(fd, std_fd);
	close(fd);
	return (save_std_fd);
}

void	restore_stdin_out(int save_std_fd, int fd, int save_std_fd2, int fd2)
{
	dup2(save_std_fd, fd);
	close(save_std_fd);
	dup2(save_std_fd2, fd2);
	close(save_std_fd2);
}
