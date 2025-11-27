/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 15:54:38 by omawele           #+#    #+#             */
/*   Updated: 2025/11/27 09:32:12 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"
// #include <stdio.h>

void	ft_free_buffer_bonus(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
}

int	ft_read_fd_bonus(int fd, char **buffer)
{
	char	*tmp;
	char	*buf_tmp;
	int		read_bytes;

	tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (tmp == NULL)
		return (0);
	read_bytes = read(fd, tmp, BUFFER_SIZE);
	tmp[BUFFER_SIZE] = '\0';
	while (read_bytes > 0)
	{
		if (read_bytes < BUFFER_SIZE)
			tmp[read_bytes] = '\0';
		buf_tmp = *buffer;
		*buffer = ft_strjoin(buf_tmp, tmp);
		ft_free_buffer_bonus(&buf_tmp);
		if (*buffer == NULL)
			return (0);
		if (ft_strchr(*buffer, '\n') || read_bytes < BUFFER_SIZE)
			break ;
		read_bytes = read(fd, tmp, BUFFER_SIZE);
	}
	ft_free_buffer_bonus(&tmp);
	return (read_bytes);
}

char	*ft_find_newline_bonus(char **buffer, char *line, char *newline)
{
	char	*buffer_sub;

	if (newline == NULL && ft_strchr(*buffer, '\0'))
	{
		line = ft_strdup(*buffer);
		ft_free_buffer_bonus(buffer);
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
		ft_free_buffer_bonus(&line);
		return (NULL);
	}
	ft_free_buffer_bonus(buffer);
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
			ft_free_buffer_bonus(buffer);
			*buffer = NULL;
			return ;
		}
		if (!tmp)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer[1024] = {NULL};
	char		*line;
	char		*is_newline;
	int			i;

	line = NULL;
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		while (i < 1024)
		{
			ft_free_buffer_bonus(&buffer[i]);
			i++;
		}
		return (NULL);
	}
	ft_next_line_bonus(&buffer[fd], fd);
	if (buffer[fd] == NULL)
		return (NULL);
	is_newline = ft_strchr(buffer[fd], '\n');
	line = ft_find_newline_bonus(&buffer[fd], line, is_newline);
	if (line == NULL)
		return (NULL);
	return (line);
}
/*int main(void)
{
	int fd = open("41_with_nl", O_RDONLY);
	char *s = "Zan";
	// int round = 0;
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("%s", s);
		if (s)
			free(s);
	}
	return (0);
}*/