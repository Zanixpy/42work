#include "libft.h"

static int lenL(char *str)
{
    int n;

    n = 0;
    while (*str)
    {
        n++;
        str++;
    }
    return (n);
}


char    *ft_strnstr(char *big, char *little, unsigned int len)
{
    int i;
    int j;

    if (*little == '\0')
        return (big);
    if (lenL(little) > len)
        return (0);
    i = 0;
    while (*big && i++ < len)
    {
        j = 0;
        if (*big == little[j])
        {
            while (*big == little[j++] && i++ < len)
            {
                if (little[j] == '\0')
                    return ((big - (j - 1)));
                big++;           
            }
        } 
        else
            big++;
    }
    return (0);
}
