#include "libft.h"

char    *ft_strchr(const char *s, int c)
{
    char src;

    src = c;
    while (*s)
    {
        if (*s == src)
            return ((char *)s);
        s++;
    }
    if (*s == src)
        return ((char *)s);
    return (0);
}