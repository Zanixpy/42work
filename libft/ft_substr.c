#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *tmp;
    unsigned int n;

    if (start >= len)
        return (0);
    tmp = malloc((len - start) * sizeof(char));
    if (tmp == 0)
        return (0);
    n = 0;
    while (start < len)
    {
        tmp[n] = s[start];
        start++;
        n++; 
    }
    return (tmp);
}
