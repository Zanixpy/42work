#include "libft/libft.h"
#include "libftprintf.h"
#include <stdio.h>

char    *ft_create_string(char **format, char **var_convert, int *read_format)
{
    char *tmp;
    char *format_sub;
    char *final;
    int  new_position;

    format_sub = ft_substr(*format, 0, *read_format - 1);
    if (format_sub == NULL)
        return (NULL);
    tmp = ft_strjoin(format_sub, *var_convert);
    if (tmp == NULL)
        return (NULL);
    new_position = ft_strlen(tmp) - 1;
    free(format_sub);
    free(*var_convert);
    format_sub = ft_substr(*format, *read_format + 1,  ft_strlen(*format + *read_format + 1));
    if (format_sub == NULL)
        return (NULL);
    free(*format);
    final = ft_strjoin(tmp, format_sub);
    free(tmp);
    free(format_sub);
    if (final == NULL)
        return (NULL);
    *read_format = new_position;
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

    var = 0;
    if (format == 1)
    {
        var_int = va_arg(*args, int);
        var = &var_int;
    }
    else if (format == 2)
    {
        var_unsigned_int = va_arg(*args, unsigned int);
        printf("Var_unsigned_int : %u\n", var_unsigned_int);
        if (var_unsigned_int < 0)
            var_unsigned_int = UINT_MAX - var_unsigned_int;
        var = &var_unsigned_int;
    }
    else if (format == 3)
    {
        var_char = va_arg(*args, int);
        var = &var_char;
    }
    else if (format == 4)
    {
        var_string = va_arg(*args, char *);
        return (var_string);
    }
    return (var);
}

char    *ft_convert(char c, va_list *args)
{
    char *var_convert;
    int   format;
    void  *var;

    var_convert = NULL;
    format = ft_search_format(c);
    if (!format)
        return (NULL);
    var = ft_cast(format, args);
    if (format == 1 || format == 2)
        var_convert = ft_itoa(* (int *) var);
    else if (format == 3)
        var_convert = ft_calloc(2, sizeof(char)); 
    else if (format == 4)
        var_convert = ft_strdup((const char *) var);
    if (var_convert == NULL)
        return (NULL);
    if (format == 3)
        var_convert[0] = * (int *) var;
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
        if (final[read_format] == '%')
        {
            read_format++;
            var_convert = ft_convert(final[read_format], &args);
            if (var_convert == NULL)
                return (1);
            final = ft_create_string(&final, &var_convert, &read_format);
            if (final == NULL)
                return (1);
        }
        read_format++;
    }
    ft_putstr_fd(final, 1);
    free(final);
    va_end(args);
    return (0);
}

