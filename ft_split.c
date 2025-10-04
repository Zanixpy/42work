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
    int i;
    int o;

    words = count_words(s,c);
    tab = (char **)malloc((words + 1) * sizeof(char *));
    if (tab == 0)
        return (0);
    n = 0;
    o = 0;
    while (n < words)
    {
        if (*s != c && (o == 0 || o == 2))
        {        
            if (o == 0)
            {
                tab[n] = malloc((ft_strlenV(s,c) + 1 ) * sizeof(char));
                o = 2;
                i = 0; 
            }
            tab[n][i] = *s;
            i++;
        } else if (*s == c && o == 2)
        {
            tab[n][i] = '\0';
            n++;
            o = 0;
        }
        s++;
    }
    tab[n] = 0;
    return (tab);
}

int main(void)
{
    const char *str = "Puree chaud en tout cas.";
    char **tab = ft_split(str, ' ');
    while (*tab != 0)
    {
        printf("%s\n", *tab);
        tab++;
    }
    free(tab);
    return (0);
}