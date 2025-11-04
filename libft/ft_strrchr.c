#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char *tmp;
    char src;

    src = c;
    tmp = 0;
    while (*s)
    {
        if (*s == src)
            tmp = (char *) s;
        s++;
    }
    if (*s == src)
        return ((char *)s);
    return (tmp);
}