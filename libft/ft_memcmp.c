#include "libft.h"

int ft_memcmp( const void *s1, const void *s2, size_t n )
{
    const unsigned char *firstB;
    const unsigned char *secondB;
    size_t size;

    firstB = (const unsigned char *) s1;
    secondB = (const unsigned char *) s2;
    size = 0;
    while (size < n)
    {
        if (firstB[size] < secondB[size])
            return (-1);
        else if (firstB[size] > secondB[size])
            return (1);
        size++;
    }
    return (0);
}