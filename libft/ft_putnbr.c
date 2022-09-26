#include "libft.h"

int ft_putnbr(int nb)
{
	int length;

	length = 0;
	if (nb < 0)
	{
		length += ft_putchar_fd('-', 1);
		nb = -nb;
	}
	if (nb >= 10)
	{
		length += ft_putnbr(nb / 10);
	}
	length += ft_putchar_fd(nb % 10 + '0', 1);
	return (length);
}