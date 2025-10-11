#include "libft.h"

int isprint(int character)
{
    char c;

    c = character;
    if (c > 31 && c < 127)
        return (1);
    return (0);
}