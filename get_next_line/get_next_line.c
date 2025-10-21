#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


void ft_free(char *ptr)
{
    free(ptr);
}


char *ft_read(int fd)
{
    char *buffer;
    int read_bytes;
    buffer = (char *)malloc(BUFFER_SIZE * sizeof(char));
    if (buffer == 0)
        return (0);
    read_bytes = read(fd, buffer, BUFFER_SIZE);
    if (read_bytes == 0)
        return (0);
    return (buffer);
}

void ft_find_newline(char *buffer)
{
    char *ptr;
    ptr = ft_strchr(buffer, '\n');
    

}

char *get_next_line(int fd)
{
    static char *buffer;
    char *line;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buffer = ft_read(fd);
    if (buffer == 0)
        return (0);


    return(line);

}

int main(void)
{
    int fd = open("text.txt", O_RDWR);
    close(fd);
    return (0);
}