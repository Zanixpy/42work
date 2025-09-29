#include "libft.h"

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