/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:54:38 by omawele           #+#    #+#             */
/*   Updated: 2025/11/21 16:31:48 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*ft_last_line_bonus(char **read_tmp, int read_bytes)
{
	char	*tmp;

	tmp = ft_substr(*read_tmp, 0, read_bytes);
	if (tmp == NULL)
		return (NULL);
	free(*read_tmp);
	return (tmp);
}

int	ft_read_fd_bonus(int fd, char **buffer)
{
	char	*tmp;
	char	*buf_tmp;
	int		read_bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (0);
	tmp[BUFFER_SIZE] = 0;
	read_bytes = read(fd, tmp, BUFFER_SIZE);
	while (read_bytes > 0)
	{
		if (read_bytes < BUFFER_SIZE)
			tmp = ft_last_line_bonus(&tmp, read_bytes);
		buf_tmp = *buffer;
		*buffer = ft_strjoin(buf_tmp, tmp);
		free(buf_tmp);
		if (*buffer == NULL)
			return (0);
		if (ft_strchr(*buffer, '\n') || read_bytes < BUFFER_SIZE)
			break ;
		read_bytes = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (read_bytes);
}

char	*ft_find_newline_bonus(char **buffer, char *line, char *newline)
{
	char	*buffer_sub;

	if (newline == NULL && ft_strchr(*buffer, '\0'))
	{
		line = ft_strdup(*buffer);
		free(*buffer);
		if (!line)
			return (NULL);
		*buffer = NULL;
		return (line);
	}
	else if (newline == NULL)
		return (NULL);
	line = ft_substr(*buffer, 0, (ft_strlen(*buffer) - ft_strlen(newline) + 1));
	if (line == NULL)
		return (NULL);
	buffer_sub = ft_substr(newline, 1, ft_strlen(newline) - 1);
	if (buffer_sub == NULL)
	{
		free(line);
		return (NULL);
	}
	free(*buffer);
	*buffer = buffer_sub;
	return (line);
}

void	ft_next_line_bonus(char **buffer, int fd)
{
	int	tmp;

	if (!(*buffer))
	{
		*buffer = malloc(sizeof(char));
		if (*buffer == NULL)
			return ;
		(*buffer)[0] = '\0';
	}
	if (!(ft_strchr(*buffer, '\n')))
	{
		tmp = ft_read_fd_bonus(fd, buffer);
		if (!tmp && (*buffer)[0] == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return ;
		}
		if (!tmp)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024];
	char		*line;
	char		*is_newline;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
		return (NULL);
	ft_next_line_bonus(&buffer[fd], fd);
	if (buffer[fd] == NULL)
		return (NULL);
	is_newline = ft_strchr(buffer[fd], '\n');
	line = ft_find_newline_bonus(&buffer[fd], line, is_newline);
	if (line == NULL)
		return (NULL);
	return (line);
}
