#include "libft.h"

void    ft_bzero(void *s, unsigned int n)
{
    unsigned char *d;
    unsigned int i;
    
    d = (unsigned char *) s;
    i = 0;
    while (i < n)
    {
        d[i] = 0;
        i++;
    }
}

