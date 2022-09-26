#include "ft_printf.h"

int	ft_printf(const char *str, ...)
{
	int i;
	int length;
	va_list args;
	char *text;
	char *value;	

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
				length += ft_putchar_fd(va_arg(args, int), 1);
			else if (str[i] == 'd' || str[i] == 'i')
			{
				value = ft_itoa(va_arg(args, int));
				ft_putstr(value);
				length += ft_strlen(value);
				free(value);
			}
			else if (str[i] == 's')
			{
				text = va_arg(args, char *);
				if (!text)
					length += ft_putstr("(null)");
				else
					length += ft_putstr(text);
			}
			else if (str[i] == '%')
				length += ft_putchar_fd('%', 1);
			else if (str[i] == 'p')
			{
				ft_putstr("0x");
				length += 2;
				value = ft_unsigned_to_hex(va_arg(args, unsigned long int), str[i]);
				ft_putstr(value);
				length += ft_strlen(value);
				free(value);
			}
			else if (str[i] == 'u')
			{
				value = ft_unsigned_to_ascii(va_arg(args, unsigned long));
				ft_putstr(value);
				length += ft_strlen(value);
				free(value);
			}
			else if (str[i] == 'x' || str[i] == 'X')
			{
				value = ft_unsigned_to_hex(va_arg(args, unsigned int), str[i]);
				ft_putstr(value);
				length += ft_strlen(value);
				free(value);
			}
		}
		else
			length += ft_putchar_fd(str[i], 1);
		i++;
	}
	va_end(args);
	return (length);
}
