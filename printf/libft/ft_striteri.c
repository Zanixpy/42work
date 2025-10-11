#include "libft.h"

void ft_striteri(char *s, void (*f)(unsigned int, char*))
{    
    int n;

    if (!s || !f)
        return;
    n = 0;
    while (s[n])
    {
        (*f)(n,(s + n));
        n++;
    }
}




