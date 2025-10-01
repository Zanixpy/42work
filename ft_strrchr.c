#include "libft.h"
#include <stdio.h>

char    *ft_strrchr(char *s, int c)
{
    char *tmp;

    tmp = 0;
    while (*s)
    {
        if (*s == c)
            tmp = s;
        s++;
    }
    return (tmp);
}

int main(void)
{
    char *s = "Salut ZanZoekiz";
    printf("%s\n", ft_strrchr(s, 'Z'));
    return (0);
}