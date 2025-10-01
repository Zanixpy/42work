#include "libft.h"
#include <stdio.h>

char    *ft_strchr(char *s, int c)
{
    while (*s)
    {
        if (*s == c)
            return (s);
        s++;
    }
    return (0);
}

int main(void)
{
    char *s = "Salut Zan";
    printf("%s\n", ft_strchr(s, 'Z'));
    return (0);
}