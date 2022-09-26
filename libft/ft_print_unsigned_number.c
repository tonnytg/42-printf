#include "libft.h"

void ft_print_unsig_numb(unsigned long nb)
{
	if (nb >= 10)
		ft_print_unsig_numb(nb / 10);
	ft_putchar_fd(nb % 10 + '0', 1);
}
