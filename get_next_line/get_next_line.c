#include "get_next_line.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>

void firstT(int fd, int *read_bytes, char **buf, int *newline, int *n)
{
    int result = *read_bytes;
    int next = *newline;
    char *str = *buf;
    int i = *n;
    while ((result = read(fd, str, BUFFER_SIZE)) > 0 && next == 0)
    {
        i = 0;
        while (i < result)
        {
            write(1, (str + i), 1);
            if (str[i] == '\n')
            {
                next++;
                break;
            }
            i++;
        }
        if (i == 0)
        {
            free(str);
            str = (char *)malloc(BUFFER_SIZE * sizeof(char));
        }else
            break;  
    }
    *newline = next;
    *n = i;
    *read_bytes = result;
}

void secondT(int read_bytes, char **buf, int *newline, int *n)
{
    int next = *newline;
    char *str = *buf;
    int i = *n + 1;
    if (next > 0)
    {
        next = 0;
        while (i < read_bytes)
        {
            write(1, (str + i), 1);
            if (str[i] == '\n')
            {
                next++;
                break;
            }
            i++;
        }      
    }
    *newline = next;
    *n = i;      
}

char *get_next_line(int fd)
{
    static int read_bytes = 0;
    static char *buf;
    static int n = 0;
    static int newline = 0;

    if (newline == 0)
    {
        buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
        if (buf == 0)
            return (0);
        firstT(fd, &read_bytes, &buf, &newline, &n);
    }else
    {
        secondT(read_bytes, &buf, &newline, &n);
        if (newline == 0)
        {
            free(buf);
            buf = (char *)malloc(BUFFER_SIZE * sizeof(char));
            if (buf == 0)
                return (0);
        }
        firstT(fd, &read_bytes, &buf, &newline, &n);
    }
    if (read_bytes == 0)
        return (0);
    return ("Test");  
}

int main(void)
{
    int fd = open("text.txt", O_RDWR);
    get_next_line(fd);
    get_next_line(fd);
    close(fd);
    return (0);
}