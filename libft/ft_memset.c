#include "libft.h"

void    *ft_memset(void *pointer, int value, size_t count)
{
    unsigned char *d;
    size_t n;

    d = (unsigned char *) pointer;
    n = 0;
    while (n < count)
    {
        d[n] = value;
        n++;
    }
    return (d);
}