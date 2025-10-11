#include "libft.h"

int ft_tolower(int character)
{
    char c;

    c = character;
    if ((c >= 'A' && c <= 'Z'))
        c += 32;
    return (c);
}