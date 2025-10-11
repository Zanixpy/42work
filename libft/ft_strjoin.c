#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
    char *tmp;
    unsigned int n;
    size_t fsize;
    size_t ssize;

    fsize = ft_strlen(s1);
    ssize = ft_strlen(s2);
    tmp = (char *) malloc((fsize + ssize + 1) * sizeof(char));
    if (tmp == 0)
        return (0);
    n = 0;
    while (*s1)
    {
        tmp[n] = *s1;
        s1++;
        n++;
    }
    while (*s2)
    {
        tmp[n] = *s2;
        s2++;
        n++;
    }
    tmp[n] = '\0';
    return (tmp);
}
