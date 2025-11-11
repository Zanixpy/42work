#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>


char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	n;
	char			*tmp;

	if ((start == 0 && len == 0) || start >= ft_strlen(s))
	{
		tmp = malloc(sizeof(char));
		if (tmp == NULL)
			return (NULL);
		tmp[0] = '\0';
		return (tmp);
	}
	if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	tmp = malloc((len + 1) * sizeof(char));
	if (tmp == NULL)
		return (NULL);
	n = 0;
	while (s[start] && n < len)
	{
		tmp[n] = s[start];
		n++;
		start++;
	}
	tmp[n] = '\0';
	return (tmp);
}


char    *ft_read_fd(int fd)
{
    char    *tmp;
    char    *buffer;
    int     read_fd;

    tmp = ft_calloc((BUFFER_SIZE + 1), sizeof(char));
    buffer = NULL;
    if (tmp == NULL)
        return (NULL);
    read_fd = read(fd, tmp, BUFFER_SIZE);
    while (read_fd > 0)
    {
        if (ft_strchr(tmp, '\n'))
        {
            buffer = ft_strjoin(buffer, tmp);
            if (buffer == NULL)
                return (NULL);
            free(tmp);
            return (buffer);
        }
        read_fd = read(fd, tmp, BUFFER_SIZE);
    }    
    if (read_fd <= 0)
        return (NULL);
    return (tmp);
}

char    *ft_find_newline(char **buffer)
{
    char *tmp;
    char *line;
    char *buffer_sub;
    char *tmp_s;

    tmp = *buffer;
    tmp_s = ft_strchr(*buffer, '\n');
    if (tmp_s == NULL)
        return (NULL);
    line = ft_substr(*buffer, 0, tmp_s - tmp - 1);
    if (line == NULL)
        return (NULL);
    buffer_sub = ft_substr(*buffer, tmp - tmp_s, ft_strlen(tmp));
    if (buffer_sub == NULL)
        return (NULL);
    free(*buffer);
    buffer = buffer_sub;
    return (line);
}

char    *ft_next_line(char *buffer, int fd)
{
    char *tmp;
    char *buf;

    buf = ft_strdup(buffer);
    if (buf == NULL)
        return (NULL);
    if (!(ft_strchr(buffer, '\n')))
    {
        tmp = ft_read_fd(fd);
        if (tmp == NULL)
            return (NULL);
        free(buffer);
        buffer = ft_strjoin(buf, tmp);
        free(tmp);
        if (buffer == NULL)
            return (NULL);
    }
    return (buffer);
}

char *get_next_line(int fd)
{
    char    *line;
    static char    *buffer;

    if (fd < 0 || BUFFER_SIZE <= 0)
        return (NULL);
    if (!buffer)
    {
        buffer = ft_calloc(1, 1);
        if (buffer == NULL)
            return (NULL);
    }
    buffer = ft_next_line(buffer, fd);
    line = ft_find_newline(&buffer);
    return (line);
}

int main(void)
{
    int fd = open("text.txt", O_RDWR);
    char *s;
    int round = 0;
    while ((s = get_next_line(fd)) != 0) 
    {
        printf("La string : %s et le round : %d \n",s,round);
        round++;
    }
    close(fd);
    return (0);
}