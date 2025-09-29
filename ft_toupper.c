#include "libft.h"

int ft_toupper(int character)
{
    char c;

    c = character;
    if ((c >= 'a' && c <= 'z'))
        c -= 32;
    return (c);
}