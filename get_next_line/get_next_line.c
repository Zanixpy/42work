/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omawele <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:21:00 by omawele           #+#    #+#             */
/*   Updated: 2025/11/14 16:29:18 by omawele          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_last_line(char **last_l, int read_bytes)
{
	char	*tmp;

	tmp = ft_substr(*last_l, 0, read_bytes);
	if (tmp == NULL)
		return (NULL);
	free(*last_l);
	return (tmp);
}

char	*ft_read_fd(int fd, char *buffer)
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
			return (buffer);
		read_fd = read(fd, tmp, BUFFER_SIZE);
	}
	free(tmp);
	return (NULL);
}

char	*ft_find_newline(char **buffer)
{
	char	*tmp;
	char	*line;
	char	*buffer_sub;
	int		tmp_len;
	int		start;

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
	tmp_len = ft_strlen(tmp);
	start = ft_strlen(*buffer) - tmp_len + 1;
	line = ft_substr(*buffer, 0, start);
	if (line == NULL)
		return (NULL);
	buffer_sub = ft_substr(tmp, 1, tmp_len - 1);
	if (buffer_sub == NULL)
		return (NULL);
	free(*buffer);
	*buffer = buffer_sub;
	return (line);
}

void	ft_next_line(char **buffer, int fd)
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

char	*get_next_line(int fd)
{
	static char	*buffer;
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

/*
int main(void)
{
    int fd = open("text.txt", O_RDWR);
    char *s;
    while ((s = get_next_line(fd)) != NULL) 
    {
        printf("La string : %s\n",s);
        if (s != NULL)
            free(s);
    }
    close(fd);
    return (0);
}*/
