#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

int main(void)
{
    int a = 255;
    int b = -3721;
    char *str = "Schadrac";
    printf("(printf) pointer : %p, string : %s, char : %c, int : %i et %d, unsigned int : %u, hexa upper : %X, hexa lower : %x et %% \n",str, str, *str, b, b, b, a, a);
    ft_printf("(ft_printf) pointer : %p, string : %s, char : %c, int : %i et %d, unsigned int : %u, hexa upper : %X, hexa lower : %x et %% \n",str, str, *str, b, b, b, a, a);
    return (0);
}


