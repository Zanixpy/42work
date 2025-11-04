#include "libft.h"

int ft_isascii(int c)
{
    unsigned char s;

    s = c;
    if (c == 0)
        return (-1);
    if (s >= 0 && s <= 127)
        return (s);
    return (0);
}