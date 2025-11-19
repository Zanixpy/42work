/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:54:38 by omawele           #+#    #+#             */
/*   Updated: 2025/11/19 16:12:54 by omawele          ###   ########.fr       */
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

char	*ft_read_fd_bonus(int fd, char *buffer)
{
	char	*tmp;
	int		read_fd;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	tmp[BUFFER_SIZE] = '\0';
	read_fd = read(fd, tmp, BUFFER_SIZE);
	while (read_fd > 0)
	{
		if (read_fd < BUFFER_SIZE)
			tmp = ft_last_line(&tmp, read_fd);
		buffer = ft_strjoin(buffer, tmp);
		if (buffer == NULL)
			return (NULL);
		if (ft_strchr(tmp, '\n') || read_fd < BUFFER_SIZE)
		{
			free(tmp);
			return (buffer);
		}
		read_fd = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (NULL);
}

char	*ft_find_newline_bonus(char **buffer)
{
	char	*tmp;
	char	*line;
	char	*buffer_sub;

	tmp = ft_strchr(*buffer, '\n');
	if (tmp == NULL && ft_strchr(*buffer, '\0'))
	{
		line = ft_strdup(*buffer);
		if (!line)
			return (NULL);
		free(*buffer);
		*buffer = NULL;
		return (line);
	}
	else if (tmp == NULL)
		return (NULL);
	line = ft_substr(*buffer, 0, (ft_strlen(*buffer) - ft_strlen(tmp) + 1));
	if (line == NULL)
		return (NULL);
	buffer_sub = ft_substr(tmp, 1, ft_strlen(tmp) - 1);
	if (buffer_sub == NULL)
		return (NULL);
	free(*buffer);
	*buffer = buffer_sub;
	return (line);
}

void	ft_next_line_bonus(char **buffer, int fd)
{
	char	*tmp;

	if (!(*buffer))
	{
		*buffer = malloc(sizeof(char));
		if (*buffer == NULL)
			return ;
		(*buffer)[0] = '\0';
	}
	if (!(ft_strchr(*buffer, '\n')))
	{
		tmp = ft_read_fd(fd, *buffer);
		if (!tmp && (*buffer)[0] == '\0')
		{
			free(*buffer);
			*buffer = NULL;
			return ;
		}
		if (!tmp)
			return ;
		free(*buffer);
		*buffer = tmp;
	}
}

char	*get_next_line_bonus(int fd)
{
	static char	**buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	ft_next_line(&buffer, fd);
	if (buffer == NULL)
		return (NULL);
	line = ft_find_newline(&buffer);
	if (line == NULL)
		return (NULL);
	return (line);
}
