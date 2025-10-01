//#include "libft.h"
#include <stdio.h>
#include <string.h>

void    *ft_memcpy(void *dest, const void *src, unsigned int n)
{
    unsigned char *d;  
    unsigned char *s;
    int i;

    d = (unsigned char *) dest;
    s = (unsigned char *) src;
    i = 0;
    while (i < n)
    {
        d[i] = s[i];
        i++;
    }

    return (d);
}


int main() {
    int x = 305419896;  // 0x12345678
    unsigned char *p = (unsigned char *)&x;

    printf("Valeur de x = %d\n", x);
    printf("Octets en mémoire :\n");
    for (int i = 0; i < sizeof(int); i++) {
        printf("Octet %d : %u (0x%02X)\n", i, p[i], p[i]);
    }

    return 0;
}
