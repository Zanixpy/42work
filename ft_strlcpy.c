#include "libft.h"

static int lenL(char *str)
{
    int n;

    n = 0;
    while (*str)
    {
        n++;
        str++;
    }
    return (n);
}

unsigned int    ft_strlcpy(char *dst, char *src, unsigned int n)
{
    unsigned int i;
    unsigned int j;
    
    i = 0;
    j = lenL(dst);
    while (src[i] && (j + i) < (n - 1))
    {
        dst[j + i] = src[i];
        i++;
    }
    dst[j + i] = '\0';
    return (lenL(src));
}

