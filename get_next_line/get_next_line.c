#include "get_next_line.h"

char *get_next_line(int fd)
{
    static char buf;
    int i;
    int n;

    i = 0;
    if (fd < 0 )
        return (0);
    while (read(fd,buf, BUFFER_SIZE) != 0)
    {
    }
    
    
    
    return (0);
}