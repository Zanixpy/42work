#include "libft.h"

void    *ft_memmove(void *dest, void *src, unsigned int n)
{
    unsigned char   *d;
    unsigned char   *s;
    unsigned int i;

    d = (unsigned char *) dest;
    s = (unsigned char *) src;
    i = 0;
    if (d > s)
    {
        while ((n - i) > 0)
        {
            d[n - 1 - i] = s[n - 1 - i];
            i++;
        }
    }
    else 
    {
        while (i < n)
        {
            d[i] = s[i];
            i++;
        }
    }
    return (dest);
}