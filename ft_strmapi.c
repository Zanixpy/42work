#include "libft.h"

char *ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
    char *str;
    int n;

    str = ft_strdup(s);
    n = 0;
    while (str[n])
    {
        str[n] = (*f)(n,str[n]);
        n++;
    }
    return(str);
}
