#ifndef LIBFTPRINTF_F
# define LIBFTPRINTF_F

# include <stdarg.h>
# include "/libft/libft.h"

int ft_printf(const char *format, ...);
int ft_search_format(char c);
void     *ft_cast(int format, va_list *args);
char    *ft_convert(char c, va_list *args);
char    *ft_create_string(char **format, char **var_convert, int read_format);

#endif