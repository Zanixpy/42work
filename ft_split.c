#include "libft.h"

static int count_words(char const *s, char c)
{
    int n;
    int c;

    n = 0;
    c = 0;
    while (*s)
    {
        if (*s != c && n == 0)
        {
            c++;
            n = 1;
        }
        else if (*s == c && n == 1)
            n == 0;
        s++;
    }
    return (c);    
}

static size_t ft_strlenV(const char *str, char c)
{
    int n;

    n = 0;
    while (*str != c)
    {
        n++;
        str++;
    }
    return (n);
}


char **ft_split(char const *s, char c)
{
    char **tab;
    int words;
    int n;

    words = count_words(s,c);
    tab = (char **)malloc((words + 1) * sizeof(char *));
    if (tab == 0)
        return (0);
    n = 0;
    while (n < words)
    {
        /* code */
    }
    
}
