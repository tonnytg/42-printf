#include "ft_printf.h"
#include <unistd.h>
#include <string.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
}

void ft_putstr(char *str)
{
	int i;
	i = 0;
	while (str[i] != '\0')
	{
		ft_putchar(str[i]);
		i++;
	}
}

void ft_putnbr(int nb)
{
	if (nb < 0)
	{
		ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		ft_putnbr(nb / 10);
	}
	ft_putchar(nb % 10 + '0');
}

int ft_printf(const char *args, ...)
{
	int i;
	int length;
	va_list arg;

	i = 0;
	length = strlen(args);
	va_start(arg, args);
	while (i < length)
	{
		if (args[i] == '%')
		{
			i++;
			if (args[i] == 'd')
				while (i <= length + 1)
				{
					ft_putchar(va_arg(arg, int));
					i++;
				}
			else if (args[i] == 's')
				ft_putstr(va_arg(arg, char *));
			else if (args[i] == 'c')
				ft_putchar(va_arg(arg, int));
			else if (args[i] == '%')
				ft_putchar('%');
		}
		i++;
	}
	va_end(arg);
	return (0);
}

