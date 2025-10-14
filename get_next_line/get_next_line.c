#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>

char *get_next_line(int fd)
{
    char *buf;
    static int read_bytes;
    //int n;

    if (fd < 0 )
        return (0);
    buf = (char *) malloc(1 * sizeof(char));
    if (buf == 0)
        return (0);
    while ((read_bytes = read(fd, buf,  1)) > 0)
    {
        if (buf == 0)
            return (0);
        /*if (buf[0] == '\n' || buf[0] == '\0')
            return (0);*/
        write(1, buf, 1);
        free(buf);
        buf = (char *) malloc(1 * sizeof(char));
    }
    if (read_bytes == 0 || read_bytes < 0)
        return (0);
    return ("Test");    
}

int main(void)
{
    int fd = open("text.txt", O_RDWR);
    while (get_next_line(fd) != 0);    
    close(fd);
    return (0);
}