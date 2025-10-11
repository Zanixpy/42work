#include "libft.h"

char    *ft_strrchr(const char *s, int c)
{
    char *tmp;

    tmp = 0;
    while (*s)
    {
        if (*s == c)
            tmp = (char *) s;
        s++;
    }
    return (tmp);
}