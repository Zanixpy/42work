#include "libft.h"

int ft_isalpha(int character)
{
    char c;

    c = character;
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
        return (1);
    return (0);
}