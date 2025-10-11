#include "libft.h"

int ft_atoi(const char *str)
{
    int result;
    int sign;

    result = 0;
    sign = 1;
    while (*str == ' ')
        str++;
    if (*str == '+')
        str++;
    else if (*str == '-')
        sign = -sign;
    while (*str >= '0' && *str <= '9')
    {
        result = (result * 10) + (*str - '0');
        str++;        
    }
    return (result * sign);
}