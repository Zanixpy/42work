#include "libftprintf.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char    *ft_create_string(char **format, char **var_convert, int read_format)
{
    char *tmp;
    char *format_sub;
    int  format_rest;
    char *final;

    format_sub = ft_substr(*format, 0, read_format - 2);
    if (format_sub == NULL)
        return (NULL);
    tmp = ft_strjoin(format_sub, *var_convert);
    if (tmp == NULL)
        return (NULL);
    free(format_sub);
    free (*var_convert);
    format_rest = ft_strlen(*format) - ft_strlen(*format + read_format + 1);
    format_sub = ft_substr(*format, read_format + 1,  format_rest);
    if (format_sub == NULL)
        return (NULL);
    free(*format);
    final = ft_strjoin(tmp, format_sub);
    free(tmp);
    free(format_sub);
    if (final == NULL)
        return (NULL);
    return (final);
}


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

void     *ft_cast(int format, va_list *args)
{
    char *var_string;
    char var_char;
    int  var_int;
    unsigned int var_unsigned_int;
    void    *var;

    if (format == 1)
    {
        var_int = va_arg(*args, int);
        var = (void *) &var_int;
    }
    else if (format == 2)
    {
        var_unsigned_int = va_arg(*args, unsigned int);
        var = (void *) &var_unsigned_int;
    }
    else if (format == 3)
    {
        var_char = va_arg(*args, int);
        var = (void *) &var_char;

    }
    else if (format == 4)
    {
        var_string = va_arg(*args, char *);
        var = (void *) &var_string;
    }
    return (var);
}

char    *ft_convert(char c, va_list *args)
{
    char *var_convert;
    int   format;
    void  *var;

    format = ft_search_format(c);
    if (!format)
        return (NULL);
    var = ft_cast(format, args);
    if (format == 1 || format == 2)
        var_convert = ft_itoa(* (int *) var);
    else if (format == 3)
        var_convert = ft_calloc(2, sizeof(char)) ; 
    else if (format == 4)
        var_convert = ft_strdup((char *) var);
    if (var_convert == NULL)
        return (NULL);
    return (var_convert);
}


int ft_printf(const char *format, ...)
{
    va_list args;
    char    *var_convert;
    char    *final;
    int     read_format;

    final = ft_strdup(format);
    if (final == NULL)
        return (1);
    va_start(args, format);
    read_format = 0;
    while (final[read_format]) 
    {
        if (final[read_format++] == '%')
        {
            var_convert = ft_convert(final[read_format], &args);
            if (var_convert == NULL)
                return (1);
            final = ft_create_string(&final, &var_convert, read_format);
            if (final == NULL)
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
