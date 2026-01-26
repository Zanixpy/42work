/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buffer_file_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/26 13:23:10 by omawele           #+#    #+#             */
/*   Updated: 2026/01/26 14:01:51 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int create_buffer_file(void)
{
    int buffer_file;

    buffer_file = open("buffer_file.txt", O_CREAT, 700 | 010 | 001);
    if (buffer_file == -1)
        return (EXIT_FAILURE);
    return (buffer_file);
}

int write_on_buffer(int wr_fd, int rd_fd)
{
    char *s;

    s = get_next_line(rd_fd);
    if (!s)
        return (EXIT_FAILURE);
    while (s)
    {
        ft_putstr_fd(s, wr_fd);
        free(s);
        s = get_next_line(rd_fd);
    }
    return (EXIT_SUCCESS);    
}

int delete_file(int fd)
{
    int status;
    
    close(fd);
    status = unlink("buffer_file.txt");
    if (status == -1)
        return (EXIT_FAILURE);
    return (EXIT_SUCCESS);
}

int	buffer_pipe(int *fds, int buffer_fd)
{
	pid_t	pid;
	int		status;

	pid = fork();
    status = 0;
	if (pid == -1)
		return (EXIT_FAIL_FORK);
	else if (pid == 0)
	{
        close(fds[1]);
        if(write_on_buffer(buffer_fd, fds[0]))
        {
            close(fds[0]);
            exit(EXIT_FAILURE);
        }
        close(fds[0]);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (WIFEXITED(status) && WEXITSTATUS(status) == EXIT_FAILURE)
				return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
