#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	int	n;

	n = 0;
	while (*str)
	{
		n++;
		str++;
	}
	return (n);
}

char	*ft_strchr(const char *s, int c)
{
	char	src;

	src = c;
	while (*s)
	{
		if (*s == src)
			return ((char *)s);
		s++;
	}
	if (*s == src)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	n;
	char			*tmp;
	size_t			fsize;
	size_t			ssize;

	fsize = ft_strlen(s1);
	ssize = ft_strlen(s2);
	tmp = malloc((fsize + ssize + 1) * sizeof(char));
	if (tmp == 0)
		return (0);
	n = 0;
	while (*s1)
	{
		tmp[n] = *s1;
		s1++;
		n++;
	}
	while (*s2)
	{
		tmp[n] = *s2;
		s2++;
		n++;
	}
	tmp[n] = '\0';
	return (tmp);
}

char	*ft_strdup(const char *s)
{
	char	*cp;
	int		n;

	n = 0;
	while (s[n])
		n++;
	cp = malloc(sizeof(char) * (n + 1));
	if (cp == 0)
		return (0);
	n = 0;
	while (s[n])
	{
		cp[n] = s[n];
		n++;
	}
	cp[n] = '\0';
	return (cp);
}

char *ft_substr(char const *s, unsigned int start, size_t len)
{
    char *tmp;
    unsigned int n;

    if (start >= len)
        return (0);
    tmp = malloc((len - start) * sizeof(char));
    if (tmp == 0)
        return (0);
    n = 0;
    while (start < len)
    {
        tmp[n] = s[start];
        start++;
        n++; 
    }
    return (tmp);
}