#include "libft/libft.h"
#include "libftprintf.h"

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

char    *ft_convert(char c, va_list *args)
{
    char *var_convert;

    var_convert = NULL;
    if (c == 'd' || c == 'i' || c == 'u')
        var_convert = ft_convert_int(c, args);
    else if (c == 'c' || c == '%')
        var_convert = ft_convert_char(c, args);
    else if (c == 's')
        var_convert = ft_convert_string(args);
    else if (c == 'x' || c == 'X')
        var_convert = ft_convert_hexa(c, args);
    else if (c == 'p')
        var_convert = ft_convert_pointer(args);
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

