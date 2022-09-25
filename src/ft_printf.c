#include "ft_printf.h"

// ft_hxnlen this function count hexa number length 
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

// ft_calc_size_i this fucntion conta os digitos base 10 or 16
size_t	ft_calc_size_base(unsigned int n, int base)
{
	size_t	i;

	i = 0;
	while (n != 0)
	{
		n = n / base;
		i++;
	}
	return (i);
}

// ft_u_to_a convert unsigned int to alphabet
char	*ft_u_to_a(unsigned int n)
{
	char	*str;
	size_t	size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_calc_size_base(n, 10);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		str[size - 1] = (n % 10) + '0';
		n = n / 10;
		size--;
	}
	return (str);
}

// ft_i_to_hex convert unsigned long long to hexa
char	*ft_i_to_hex(unsigned long long n)
{
	char	*str;
	size_t	size;

	if (n == 0)
		return (ft_strdup("0"));
	size = ft_calc_size_base(n, 16);
	str = malloc((size + 1) * sizeof(char));
	if (!str)
		return (NULL);
	str[size] = '\0';
	while (size > 0)
	{
		if (n % 16 > 9)
			str[size - 1] = (n % 16) + 'a' - 10;
		else
			str[size - 1] = (n % 16) + '0';
		n = n / 16;
		size--;
	}
	return (str);
}

// ft_itoa_hx ft_itoa_hx this functions converts an unsigned long int to a hexadecimal string
int	ft_itoa_hx(unsigned long int n, char *base)
{
	char	*str;
	int		n_digits;
	int		i;

	n_digits = ft_hxnlen(n);
	str = malloc((n_digits + 1) * sizeof(char));
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

// count_digits this function counts the number of digits in a number
int count_digits(long n)
{
	int count;

	count = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		n = -n;
		count++;
	}
	while (n > 0)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

// ft_poutnbr_un ft_print_unsigned_number
void ft_poutnbr_un(unsigned long nb)
{
	if (nb >= 10)
		ft_poutnbr_un(nb / 10);
	ft_putchar(nb % 10 + '0');
}

int ft_printf(const char *str, ...)
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
			{
				ft_putchar(va_arg(args, int));
				length++;
			}
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
				length += ft_itoa_hx(va_arg(args, unsigned long long), "0123456789abcdef");
			}
			else if (str[i] == 'u')
			{
				value = ft_u_to_a(va_arg(args, unsigned long));
				ft_putstr(value);
				length += ft_strlen(value);
				free(value);
			}
			else if (str[i] == 'x')
				length += ft_itoa_hx(va_arg(args, unsigned int), "0123456789abcdef");
			else if (str[i] == 'X')
				length += ft_itoa_hx(va_arg(args, unsigned int), "0123456789ABCDEF");
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
