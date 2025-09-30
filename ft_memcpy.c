//#include "libft.h"
#include <stdio.h>
#include <string.h>

void    ft_memcpy(void *dest, const void *src, unsigned int n)
{
    int i;

    i = 0;
    while (i < n)
    {
        dest[i = src[i];
        i++;
    }
}


int main(void)
{
    char *src = "Salut";
    char dest[10];
    dest = memcpy(dest, src, 2);
    printf("%p", dest);
    return (0);

}