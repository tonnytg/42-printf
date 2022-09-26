#include "libft.h"

char	*ft_unsigned_to_ascii(unsigned int n)
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
