#include "libft.h"

int ft_isdigit(int character)
{
    char c;

    c = character;
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}