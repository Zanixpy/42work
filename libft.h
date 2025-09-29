#ifndef LIBTF_H
# define LIBTF_H

#include <unistd.h>

int ft_isdigit(int character);
int ft_isalpha(int character);
int ft_isalnum(int character);
int ft_atoi(const char *str);
int ft_tolower(int character);
int ft_toupper(int character);
int isprint(int character);
int ft_strncmp(const char *s1, const char *s2);
int ft_strlen(const char *str);



#endif