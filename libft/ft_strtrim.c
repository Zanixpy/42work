#include "libft.h"

static int chr(char c, char const *set)
{
    while (*set)
    {
        if (ft_toupper(c) == *set || ft_tolower(c) == *set || c == *set)
                return (1);
        set++;
    }
    return (0);   
}

char *ft_strtrim(char const *s1, char const *set)
{
    char *tmp;
    unsigned int n;
    unsigned int i;

    i = 0;
    while (chr(*s1,set) == 1)
        s1++;
    n = ft_strlen(s1);
    while (chr(*(s1 + (n - 1)), set) == 1)
        n--;
    tmp = malloc((n + 1) * sizeof(char));
    if (tmp == 0)
        return (0);
    while (i < n)
    {
        tmp[i] = *s1;
        i++;
        s1++;
    }
    tmp[i] = '\0';
    return (tmp);
}