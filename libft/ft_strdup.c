#include "libft.h"

char	*ft_strdup(const char *src)
{
	char	*ptr;
	size_t	count;

	count = 0;
	ptr = malloc(sizeof(char) * ft_strlen(src) + 1);
	if (ptr == NULL)
		return (NULL);
	while (src[count])
	{
		ptr[count] = src[count];
		count++;
	}
	ptr[count] = '\0';
	return (ptr);
}