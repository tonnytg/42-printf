#include "ft_printf.h"
#include <unistd.h>
#include <string.h>

void ft_putchar(int c)
{
	write(1, &c, 1);
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

int ft_printf(const char *str, ...)
{
	int i;
	int length;
	va_list args;

	va_start(args, str);
	i = 0;
	length = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '%')
		{
			i++;
			if (str[i] == 'c')
			{
				ft_putchar(va_arg(args, int));
				length++;
			}
			else if (str[i] == 'd' || str[i] == 'i')
			{
				ft_putnbr(va_arg(args, int));
				length++;
			}
			else if (str[i] == 's')
			{
				ft_putstr(va_arg(args, char *));
				length++;
			}
			else if (str[i] == '%')
			{
				ft_putchar('%');
				length++;
			}
		}
		else
		{
			ft_putchar(str[i]);
			length++;
		}
		i++;
	}
	va_end(args);
	return (length);
}
