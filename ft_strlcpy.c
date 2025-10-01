#include "libft.h"
#include <stdio.h>
#include <bsd/string.h>

static int lenL(char *str)
{
    int n;

    n = 0;
    while (*str)
    {
        n++;
        str++;
    }
    return (n);
}

unsigned int    ft_strlcpy(char *dst, char *src, unsigned int n)
{
    int i;
    int j;
    
    i = 0;
    j = lenL(dst);
    while (src[i] && (j + i) < (n - 1))
    {
        dst[j + i] = src[i];
        i++;
    }
    dst[j + i] = '\0';
    return (lenL(src));
}

int main(void)
{
    char *src = "Heqvvvd";
    char dst[10];
    dst[0] = 'A';
    dst[1] = 'b';
    dst[2] = '\0';
    printf("%d, %ld\n", ft_strlcpy(dst, src, 7), strlcpy(dst, src, 7));
    return (0);
}