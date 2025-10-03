#include "libft.h"

void    *ft_memchr(void *s, int c, unsigned int n)
{
    unsigned char *d;
    unsigned char tmp;
    int i;

    d = (unsigned char *) s;
    tmp = c;
    i = 0;
    while (i < n)
    {
        if (d[i] == tmp)
            return (d + i);
        i++;
    }
    return (0);
}