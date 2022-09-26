#include "libft.h"

size_t	ft_calc_size_base(unsigned long int n, int base)
{
	int	i;

	if (!n)
		return (1);
	i = 0;
	while (n)
	{
		n = n / base;
		i++;
	}
	return (i);
}