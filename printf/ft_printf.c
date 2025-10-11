#include "libftprintf.h"
#include <stdio.h>

int ft_printf(const char *format, ...)
{
    va_list args;
    va_list tmp;
    va_start(args, format);

    va_copy(tmp, args);

    va_end(tmp);
    return (0);
}

int main(void)
{
    char * a = "ay%Xo";
    //int b = 41;
    //int c = 42;
    printf("%s\n", a);
    return (0);
}
