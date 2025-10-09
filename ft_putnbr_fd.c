#include "libft.h"
#include <fcntl.h>

void ft_putnbr_fd(int n, int fd)
{
    char c;

    if (fd < 0)
        return;
    c = 0;
    if (n == -2147483648)
    {
        write(fd, "-2147483648", 11);
        return;
    }
    if (n < 0)
    {
        write(fd, "-", 1);
        n = -n;
    }
    if (n > 9)
        ft_putnbr_fd((n / 10), fd);
    c = '0' + (n % 10);
    write(fd, &c, 1);
}

/*int main(void)
{
    int fd = open("test.txt", O_RDWR);
    if (fd > 0)
    {
        ft_putnbr_fd(-2147483648,fd);
    }
    close(fd);
    return (0);
    
}*/