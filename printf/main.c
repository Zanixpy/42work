#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

int main(void)
{
    void *ptr = NULL;
    ft_printf("(ft_printf) %p\n", ptr);
    printf("(printf) %p\n", ptr);
    return (0);
}