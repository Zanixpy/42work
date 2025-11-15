#include "libftprintf.h"
#include <stdio.h>
#include <string.h>

int ft_search_format(char c)
{
    if (c == 'd' || c == 'i')
        return (1);
    else if (c == 'u')
        return (2);
    else if (c == 'c')
        return  (3);
    else if (c == 's')
        return  (4);
    else if (c == '%')
        return  (5);
    return (0);
}

char    *ft_convert(char c, va_list *args)
{
    char *var_convert;
    char var_char;
    int  var_int;
    int format;

    format = ft_search_format(c);
    if (format == 1 )
        var_int = va_arg(*args, int);
    else if (format == 2)
        var_int = va_arg(*args, unsigned int);
    else if (format == 3)
        var_char = va_arg(*args, int);
    else if (format == 4)
        var_convert = va_arg(*args, char *);
    if (format == 1 || format == 2)
    {
        var_convert == ft_itoa(var_int);
        if (var_convert == NULL)
            return (NULL);
    }


    return (var_convert);
}


int ft_printf(const char *format, ...)
{
    va_list args;
    char    *var_convert;
    char    *final;
    int     read_format;

    va_start(args, format);
    read_format = 0;
    while (format[read_format]) 
    {
        if (format[read_format++] == '%')
        {
            var_convert = ft_convert(format[read_format], &args);
            if (var_convert == NULL)
                return (1);
        }
        read_format++;
    }
    va_end(args);
    ft_putstr_fd(final, 1);
    free(final);
    return (0);
}



int main(void)
{
    char *a = "%d";
    int b = 41;
    int c = 42;
    printf("%vsj\n");
    return (0);
}
