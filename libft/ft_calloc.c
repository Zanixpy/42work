#include "libft.h"

void    *ft_calloc(unsigned int nmemb, unsigned int size)
{
    unsigned char *tab;
    unsigned int n;
    unsigned int fsize;

    if (nmemb == 0 || size == 0)
    {
        tab = malloc(1);
        return ((void *)  tab);
    }
    fsize = nmemb * size;
    tab = malloc(fsize);
    if (tab == 0)
        return ((void *)  tab);
    n = 0;
    while (n < fsize)
    {
        tab[n] = 0;
        n++;
    }
    return ((void *)  tab);
}