/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <omawele@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:39:45 by omawele           #+#    #+#             */
/*   Updated: 2025/12/18 19:57:22 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_free_buffer(char **buf)
{
	if (*buf)
	{
		free(*buf);
		*buf = NULL;
	}
}

static int	ft_read_fd(int fd, char **buffer)
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
		ft_free_buffer(&buf_tmp);
		if (*buffer == NULL)
			return (0);
		if (ft_strchr(*buffer, '\n') || read_bytes < BUFFER_SIZE)
			break ;
		read_bytes = read(fd, tmp, BUFFER_SIZE);
	}
	ft_free_buffer(&tmp);
	return (read_bytes);
}

static char	*ft_find_newline(char **buffer, char *line, char *newline)
{
	char	*buffer_sub;

	if (newline == NULL && ft_strchr(*buffer, '\0'))
	{
		line = ft_strdup(*buffer);
		ft_free_buffer(buffer);
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
		ft_free_buffer(&line);
		return (NULL);
	}
	ft_free_buffer(buffer);
	*buffer = buffer_sub;
	return (line);
}

static void	ft_next_line(char **buffer, int fd)
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
		tmp = ft_read_fd(fd, buffer);
		if (!tmp && (*buffer)[0] == '\0')
		{
			ft_free_buffer(buffer);
			*buffer = NULL;
			return ;
		}
		if (!tmp)
			return ;
	}
}

char	*get_next_line(int fd)
{
	static char	*buffer = NULL;
	char		*line;
	char		*is_newline;

	line = NULL;
	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) == -1)
	{
		ft_free_buffer(&buffer);
		return (NULL);
	}
	ft_next_line(&buffer, fd);
	if (buffer == NULL)
		return (NULL);
	is_newline = ft_strchr(buffer, '\n');
	line = ft_find_newline(&buffer, line, is_newline);
	if (line == NULL)
		return (NULL);
	return (line);
}
/*int main(void)
{
	int fd = open("test.txt", O_RDONLY);
	char *s = "Zan";
	while ((s = get_next_line(fd)) != NULL)
	{
		printf("%s", s);
		if (s)
			free(s);
	}
	return (0);
}*/