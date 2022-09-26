#include "libft.h"

int	ft_len_digits(unsigned int n)
{
	if (n < 10)
		return (1);
	return (ft_len_digits(n / 10) + 1);
}
