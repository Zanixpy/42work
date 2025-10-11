#include <fcntl.h>
#include "libft.h"

void ft_putendl_fd(char *s, int fd)
{
    if (fd < 0)
        return;
    while (*s)
    {
        write(fd, s, 1);
        s++;
    }
    write(fd, "\n", 1);
}

/*int main(void)
{
    int fd = open("test.txt", O_RDWR);
    if (fd > 0)
    {
        ft_putendl_fd("super idol nichalung",fd);
        
    }
    close(fd);
    return (0);
    
}*/