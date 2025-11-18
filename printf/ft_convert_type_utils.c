#include "libft/libft.h"
#include "libftprintf.h"
#include <string.h>

char    *ft_strreverse(const char *s)
{
    char *tmp;
    int len;
    int i;

    if (!s)
        return (NULL);
    len = ft_strlen(s);
    tmp = ft_calloc(len + 1, sizeof(char));
    if (tmp == NULL)
        return (NULL);
    i = 0;
    while (i < len) 
    {
        tmp[i] = s[len - i - 1];
        i++;
    }
    return (tmp);
}

char     ft_hexa(int pos, char mode)
{
    char *hexa;

    hexa = "0123456789abcdefABCDEF";
    if (ft_isalpha(hexa[pos]) && mode == 'X')
        return (hexa[pos + 6]);
    return (hexa[pos]);
}

char    *ft_pointer_to_hexa(unsigned long var)
{
    char *var_convert;
    char *tmp;

    tmp = ft_calloc(1, sizeof(char));
    if (tmp == NULL)
        return (NULL);
    while (var != 0)
    {
        var_convert = ft_calloc(2, sizeof(char));
        if (var_convert == NULL)
            return (NULL);
        var_convert[0] = ft_hexa((var % 16), 0);
        tmp = ft_strjoin(tmp, var_convert);
        free(var_convert);
        if (tmp == NULL)
            return (NULL);
        var /= 16;
    }
    var_convert = ft_strreverse(tmp);
    free(tmp);
    if (var_convert == NULL)
        return (NULL);
    return (var_convert);  
}

char *ft_check_unsigned_int(long var)
{
    char *tmp;
    long value;

    tmp = ft_itoa(var);
    if (tmp == NULL) 
        return (NULL);
    if (tmp[0] == '-')
    {
        free(tmp);
        value = 4294967295 - var;
        tmp = ft_itoa(value);
        if (tmp == NULL)
            return (NULL);
    }
    return (tmp);
}