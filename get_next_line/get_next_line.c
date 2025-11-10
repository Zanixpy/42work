#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


char    *ft_read_fd(int fd)
{
    char    *tmp;

    tmp = malloc((BUFFER_SIZE + 1) * sizeof(char));
    if (tmp == 0)
        return (0);

}

char    *ft_find_newline(char *buffer)
{

}

char    *ft_next_line(char **buffer, int fd)
{

}

char *get_next_line(int fd)
{
    char    *line;
    static char    *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (0);
    buffer =
    line = ft_find_newline(buffer);

    return (line);
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