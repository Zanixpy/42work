#ifndef LIBFTPRINTF_F
# define LIBFTPRINTF_F

# include <stdarg.h>

int ft_printf(const char *format, ...);
char    *ft_convert_int(char c, va_list *args);
char    *ft_convert_char(char c, va_list *args);
char    *ft_convert_string(va_list *args);
char    *ft_convert_hexa(char c, va_list *args);
char    *ft_convert_pointer(va_list *args);
char    *ft_convert(char c, va_list *args);
char    *ft_create_string(char **format, char **var_convert, int *read_format);
char    *ft_strreverse(const char *s);
char     ft_hexa(int pos, char mode);
char    *ft_pointer_to_hexa(unsigned long var);
char    *ft_check_unsigned_int(long var);

#endif