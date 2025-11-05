#include "libft.h"
#include <fcntl.h>


void ft_putstr_fd(char *s, int fd)
{
    if (fd < 0)
        return;
    while (*s)
    {
        write(fd, s, 1);
        s++;
    }
    
}

/*int main(void)
{
    int fd = open("test.txt", O_RDWR);
    if (fd > 0)
    {
        ft_putstr_fd("super idol",fd);
    }
    close(fd);
    return (0);
    
}*/