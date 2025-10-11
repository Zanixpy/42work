#include "libft.h"

static int count_words(char const *s, char c)
{
    int n;
    int i;

    n = 0;
    i = 0;
    while (*s)
    {
        if (*s != c && n == 0)
        {
            i++;
            n = 1;
        }
        else if (*s == c && n == 1)
            n = 0;
        s++;
    }
    return (i);    
}

static size_t ft_strlenV(const char *str, char c)
{
    int n;

    n = 0;
    while (*str != c && *str)
    {
        n++;
        str++;
    }
    return (n);
}

void    conca(char ***tab, char const *s, int *pos, int len)
{
    int n;
    int i;

    n = *pos;
    i = 0;
    while (i < len)
    {
        (*tab)[n][i] = *s;
        s++;
        i++;
    }
    (*tab)[n][i] = '\0';
    *pos = n + 1;
}


char **ft_split(char const *s, char c)
{
    char **tab;
    int words;
    int n;
    int o;

    words = count_words(s,c);
    tab = (char **)malloc((words + 1) * sizeof(char *));
    if (tab == 0)
        return (0);
    n = 0;
    o = 0;
    while (n < words)
    {
        if (*s != c && o == 0)
        {
            o = 1; 
            tab[n] = malloc((ft_strlenV(s,c) + 1 ) * sizeof(char));
            conca(&tab, s, &n, ft_strlenV(s,c));
        } else if (*s == c && o == 1)
            o = 0;
        s++;
    }
    tab[n] = 0;
    return (tab);
}