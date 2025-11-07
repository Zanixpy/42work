#include "libft.h"

int ft_toupper(int c)
{
    char s;

    s = c;
    if ((s >= 'a' && s <= 'z'))
        s -= 32;
    return (s);
}