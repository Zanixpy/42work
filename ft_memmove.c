#include "libft.h"

void    *ft_memmove(void *dest, void *src, unsigned int n)
{
    unsigned char   *d;
    unsigned char   *s;
    unsigned char   tmp[256]; 
    unsigned int i;
    unsigned int o;

    d = (unsigned char *) dest;
    s = (unsigned char *) src;
    i = 0;
    o = 0;
    while (i < n && (d + i) != (s + i))
    {
        d[i] = s[i];
        i++;
    }
    while ((i + o) < n)
    {
        tmp[o] = s[i + o];
        o++;
    }
    o = 0;
    while ((i + o) < n)
    {
        d[i + o] = tmp[o];
        o++;
    }
    return (dest);
}