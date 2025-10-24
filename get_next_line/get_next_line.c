#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

char *ft_read(int fd, char *buf)
{
    char *buffer;
    char *tmp;
    int read_bytes;

    buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == 0)
        return (0);
    read_bytes = read(fd, buffer, BUFFER_SIZE);
    if (read_bytes == 0)
        return (0);
    if (!buf)
        return (buffer);
    tmp = ft_strjoin(buf, buffer);
    free(buffer);
    // printf("Dans ft_read\n");
    return (tmp);
}

char *ft_find_newline(char **buffer)
{
    char *ptr;
    char *line;
    char *tmp;
    
    // printf("Dans ft_find_newline\n");
    ptr = ft_strchr(*buffer, '\n');
    if (ptr == 0)
        return (0);
    // printf("Le ptr (ft_find_newline) : %s\n", ptr);
    line = ft_substr(*buffer, 0, ptr - *buffer);
    if (line == 0)
        return (0);
    // printf("La line (ft_find_newline) : %s\n", ptr);
    tmp = ft_strdup(ptr + 1);
    free(*buffer);
    *buffer = tmp;
    // printf("Dans ft_find_newline\n");
    return (line);
}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    // printf("Dans get_next_line\n");
    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buffer = ft_read(fd,buffer);
    // printf("Le buffer (get_next_line) : %s et la len : %d\n", buffer, ft_strlen(buffer));
    if (buffer == 0)
        return (0);
    line = ft_find_newline(&buffer);
    // printf("La line (get_next_line) :%s\n", line);
    return(line);
}

int main(void)
{
    int fd = open("text.txt", O_RDWR);
    char *s;
    int round = 0;
    while ((s = get_next_line(fd)) != 0) 
    {
        printf("La string : %s et le round : %d \n",s,round);
        round++;
    }
    close(fd);
    return (0);
}