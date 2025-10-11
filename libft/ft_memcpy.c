#include "libft.h"
#include <stdio.h>
#include <string.h>

void    *ft_memcpy(void *dest, const void *src, unsigned int n)
{
    unsigned char *d;  
    unsigned char *s;
    unsigned int i;

    d = (unsigned char *) dest;
    s = (unsigned char *) src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }

    return (d);
}
