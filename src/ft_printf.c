#include "ft_printf.h"
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

static int	digits(unsigned int n);
static int	is_negative(int n);

static int	ft_hxnlen(unsigned long int n)
{
	int	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n = n / 16;
		i++;
	}
	return (i);
}

int	ft_itoa_hx(unsigned long int n, char *base)
{
	char	*str;
	int		n_digits;
	int		i;

	n_digits = ft_hxnlen(n);
	str = (char *)malloc((n_digits + 1) * sizeof(char));
	i = n_digits;
	if (i == 0)
		str[0] = '0';
	while (i > 0)
	{
		str[i - 1] = base[n % 16];
		n = n / 16;
		i--;
	}
	write (1, str, n_digits);
	free (str);
	return (n_digits);
}

size_t	ft_strlen(const char *s)
{
	int	len;

	len = 0;
	while (s[len])
	{
		len++;
	}
	return ((size_t)len);
}

char	*ft_itoa(int n)
{
	char			*str;
	int				len;
	int				negative;
	unsigned int	nb;

	nb = n;
	negative = is_negative(n);
	if (negative)
		nb = n * (-1);
	len = digits(nb) + negative;
	str = malloc(len + 1);
	if (!str)
		return (NULL);
	str[len] = '\0';
	while (len--)
	{
		str[len] = (nb % 10) + '0';
		nb /= 10;
	}
	if (negative)
		str[0] = '-';
	return (str);
}

int	is_negative(int n)
{
	return (n < 0);
}

int	digits(unsigned int n)
{
	if (n < 10)
		return (1);
	return (digits(n / 10) + 1);
}

int ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int ft_putnbr(int nb)
{
	int length;

	length = 0;
	if (nb < 0)
	{
		length += ft_putchar('-');
		nb = -nb;
	}
	if (nb >= 10)
	{
		length += ft_putnbr(nb / 10);
	}
	length += ft_putchar(nb % 10 + '0');
	return (length);
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
	char *text;

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
				//int value;
				char *value;

				//value = va_arg(args, int);
				//length += ft_putnbr(value);
				value = ft_itoa(va_arg(args, int));
				ft_putstr(value);
				length += ft_strlen(value);
				free(value);
			}
			else if (str[i] == 's')
			{
				text = va_arg(args, char *);
				if (!text)
				{
					ft_putstr("(null)");
					length += 6;
				} else
				{
					ft_putstr(text);
					length += strlen(text);
				}
			}
			else if (str[i] == '%')
			{
				ft_putchar('%');
				length++;
			}
			else if (str[i] == 'p')
			{
				ft_putstr("0x");
				length += 2;
				length += ft_itoa_hx(va_arg(args, unsigned long int), "0123456789abcdef");
			}
			else if (str[i] == 'u')
			{
				ft_putnbr(va_arg(args, unsigned int));
				length++;
			}
			else if (str[i] == 'x')
			{
				length += ft_itoa_hx(va_arg(args, unsigned long int), "0123456789abcdef");
			}
			else if (str[i] == 'X')
			{
				length += ft_itoa_hx(va_arg(args, unsigned long int), "0123456789ABCDEF");
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
