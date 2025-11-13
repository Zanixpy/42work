#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int ft_last_line(char **buffer, int size)
{
    char    *tmp;

    tmp = ft_substr(*buffer, 0, size);
    if (tmp == NULL)
        return (0);
    free(*buffer);
    *buffer = tmp;
    return (1);
}

char    *ft_read_fd(int fd, char *buffer)
{
    char    *tmp;
    int     read_fd;

    tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (tmp == NULL)
        return (NULL);
    tmp[BUFFER_SIZE] = '\0';    
    read_fd = read(fd, tmp, BUFFER_SIZE);
    while (read_fd > 0)
    {
        if (ft_strchr(tmp, '\n'))
        {
            buffer = ft_strjoin(buffer, tmp);
            free(tmp);
            if (buffer == NULL)
                return (NULL);
            return (buffer);
        }
        if (read_fd < BUFFER_SIZE)
            if (!ft_last_line(&tmp, read_fd))
                return (NULL);
        buffer = ft_strjoin(buffer, tmp);
        if (buffer == NULL)
            return (NULL);
        read_fd = read(fd, tmp, BUFFER_SIZE);
    }
    free(tmp);
    return (buffer);
}

char    *ft_find_newline(char **buffer)
{
    char *tmp;
    char *line;
    char *buffer_sub;
    int  tmp_len;
    int  start;

    tmp = ft_strchr(*buffer, '\n');
    if (tmp == NULL)
    {
        if (ft_strchr(*buffer, '\0'))
            return (*buffer);
        return (NULL);
    }
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

char    *ft_next_line(char *buffer, int fd)
{
    if (buffer == NULL)
        return (NULL);
    if (!(ft_strchr(buffer, '\n')))
    {
        buffer = ft_read_fd(fd, buffer);
        if (buffer == NULL)
            return (NULL);
    }
    return (buffer);
}

char *get_next_line(int fd)
{
    char    *line;
    static char    *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!buffer)
    {
        buffer = malloc(sizeof(char));
        if (buffer == NULL)
            return (NULL);
        buffer[0] = '\0';
    }
    buffer = ft_next_line(buffer, fd);
    if (buffer == NULL)
        return (NULL);
    line = ft_find_newline(&buffer);
    return (line);
}

int main(void)
{
    int fd = open("text.txt", O_RDWR);
    char *s;
    int round = 0;
    while ((s = get_next_line(fd)) != NULL) 
    {
        printf("La string : %s et le round : %d \n",s,round);
        round++;
        free(s);
    }
    free(s);
    close(fd);
    return (0);
}