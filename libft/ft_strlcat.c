#include "libft.h"


static size_t ft_len(const char *str)
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

static size_t MIN(size_t i, size_t j)
{
    if (i > j)
        return (j);
    else
        return (i);
}

size_t ft_strlcat(char *dst, const char *src, size_t n)
{
    size_t i;
    size_t len;

    if (n == 0)
        return (ft_len(src));
    if (n <= ft_len(dst))
        return (ft_len(src) + n);
    i = 0;
    len = ft_len(dst);
    while (src[i] &&  i < (n - len - 1))
    {
        dst[len + i] = src[i];
        i++;
    }
    dst[len + i] = '\0';
    return (MIN(len, n) + ft_len(src));
}
