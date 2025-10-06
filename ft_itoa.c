#include "libft.h"

void    ft_isnegative(long *nb, int *sign)
{

    if (*nb < 0)
    {
        *sign = 1;
        *nb *= -1; 
    }
    else 
        *sign = 0;
}

char *ft_itoa(int n)
{
    char *str;
    long tmp;
    int size;
    int sign;

    size = 1;
    tmp = (long) n;
    ft_isnegative(&tmp, &sign);
    while (n /= 10)
        size++;
    size += sign;
    str = (char *)malloc((size + 1) * sizeof(char));
    if (str == 0)
        return (0);
    str[size] = '\0';
    while (size--)
    {
        str[size] = '0' + (tmp % 10) ;
        tmp /= 10;
    }
    if (sign == 1)
        str[0] = '-';
    return (str);
}