#include "libft.h"

int ft_putchar_fd(int c, int fd)
{
	write(1, &c, fd);
	return (fd);
}