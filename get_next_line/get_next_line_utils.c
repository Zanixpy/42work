#include "get_next_line.h"

int ft_strlen(const char *str)
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

char    *ft_strchr(const char *s, int c)
{   
    while (*s)
    {
        if (*s == c)
            return ((char *)s);
        s++;
    }
    return (0);
}