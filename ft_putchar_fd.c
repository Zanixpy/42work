#include "libft.h"
#include <fcntl.h>

void ft_putchar_fd(char c, int fd)
{
    write(fd, &c, 1);
}

int main(void)
{
    int fd = open("test.txt", O_RDWR);
    if (fd > 0)
    {
        ft_putchar_fd('s',fd);
    }
    close(fd);
    return (0);
    
}