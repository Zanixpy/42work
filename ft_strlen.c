#include "libft.h"

size_t ft_strlen(const char *str)
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