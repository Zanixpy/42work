#include "libft.h"

char    *ft_strdup(char *src)
{
    char    *cp;
    int n;

    n = 0;
    while (src[n])
        n++;
    cp = malloc(sizeof(char) * n);
    n = 0;
    while (src[n])
    {
        cp[n] = src[n];
        n++;
    }
    return (cp);    
}