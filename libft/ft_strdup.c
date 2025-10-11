#include "libft.h"

char    *ft_strdup(const char *s)
{
    char    *cp;
    int n;

    n = 0;
    while (s[n])
        n++;
    cp = malloc(sizeof(char) * (n + 1));
    if (cp == 0)
        return (0);
    n = 0;
    while (s[n])
    {
        cp[n] = s[n];
        n++;
    }
    cp[n] = '\0';
    return (cp);    
}