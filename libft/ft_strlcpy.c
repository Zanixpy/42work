#include "libft.h"

static size_t ft_len(const char *str)
{
    size_t n;

    n = 0;
    while (*str)
    {
        n++;
        str++;
    }
    return (n);
}

size_t ft_strlcpy(char *dst, const char *src, size_t n)
{
    size_t  i;

    if (n == 0)
        return (ft_len(src));
    i = 0;
    while (src[i] && i < (n - 1))
    {
        dst[i] = src[i];
        i++;     
    }
    dst[i] = '\0';
    return (ft_len(src));
}

