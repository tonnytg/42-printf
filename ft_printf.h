#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include "libft/libft.h"
# include <stdarg.h>

int ft_printf(const char *s, ...);
int ft_choice(char c, int length, va_list args);
int ft_get_char(va_list args);
int ft_get_str(va_list args);
int ft_get_pointer(va_list args, char c);
int ft_get_int(va_list args);
int ft_get_unsigned_to_ascii(va_list args);
int ft_get_hex(va_list args, char c);

#endif