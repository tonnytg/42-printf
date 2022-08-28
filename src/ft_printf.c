#include "ft_printf.h"

int ft_printf(const char *args, ...)
{
	int i;
	va_list arg;
	va_start(arg, args);
	i = 0;

	while (args[i])
	{
		va_arg(arg, int);
		putchar(args[i]);
		i++;
	}
	va_end(arg);
	return (0);
}

