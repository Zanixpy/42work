#ifndef LIBTF_H
# define LIBTF_H

#include <unistd.h>
#include <stdlib.h>

int ft_isdigit(int character);
int ft_isalpha(int character);
int ft_isalnum(int character);
int ft_atoi(const char *str);
int ft_tolower(int character);
int ft_toupper(int character);
int isprint(int character);
int ft_strncmp(char *s1, char *s2);
int ft_strlen(char *str);
char    *ft_strdup(char *src);
void    *ft_memcpy(void *dest, const void *src, unsigned int n);
char    *ft_strchr(char *s, int c);
char    *ft_strnstr(char *big, char *little, unsigned int len);
unsigned int    ft_strlcpy(char *dst, char *src, unsigned int n);







#endif