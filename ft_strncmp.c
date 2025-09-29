#include "libft.h"

int ft_strncmp(const char *s1, const char *s2, unsigned int n)
{
    int i;

    i = 0;
    while ((*s1 || *s2) && i < n )
    {
        if (*s1 != *s2)
            return (*s1 - *s2);
        s1++;
        s2++;
        i++;
    }
    return (0);
}