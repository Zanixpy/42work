#include "libftprintf.h"
#include <stdio.h>
#include <limits.h>
#include <string.h>

int main(void)
{

    char *str = "Zan";
    int  nb = -10;
    // int ret = ft_printf("p : %p, u : %u, s : %s, i : %i, d : %d, x : %x, X %%% : %X, %% : %% %lvv\n%", str, nb, str, nb, nb, nb, nb );
    // int ret2 = printf("p : %p, u : %u, s : %s, i : %i, d : %d, x : %x, X %%% : %X, %% : %% %lvv\n%", str, nb, str, nb, nb, nb,nb );
    int ret3 = ft_printf("%d, %sv%lvv\n%c", nb, str, 'c');
    int ret4 = printf("%d, %sv%lvv\n%c", nb, str, 'c');

    // printf("(ft_printf) : %d\n", ret);
    // printf("(printf) : %d\n", ret2);
    printf("(ft_printf) : %d\n", ret3);
    printf("(printf) : %d\n", ret4);

    return (0);
}