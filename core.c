/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/26 13:48:56 by antthoma          #+#    #+#             */
/*   Updated: 2022/09/26 13:51:18 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_get_char(va_list args)
{
	int	length;

	length = 0;
	length += ft_putchar_fd(va_arg(args, int), 1);
	return (length);
}

int	ft_get_str(va_list args)
{
	int		length;
	char	*text;

	text = va_arg(args, char *);
	if (!text)
		length = ft_putstr("(null)");
	else
		length = ft_putstr(text);
	return (length);
}

int	ft_get_pointer(va_list args, char c)
{
	int		length;
	char	*value;

	ft_putstr("0x");
	length = 2;
	value = ft_unsigned_to_hex(va_arg(args, unsigned long int), c);
	ft_putstr(value);
	length += ft_strlen(value);
	free(value);
	return (length);
}

int	ft_get_int(va_list args)
{
	int		length;
	char	*value;

	value = ft_itoa(va_arg(args, int));
	ft_putstr(value);
	length = ft_strlen(value);
	free(value);
	return (length);
}

int	ft_get_unsigned_to_ascii(va_list args)
{
	int		length;
	char	*value;

	value = ft_unsigned_to_ascii(va_arg(args, unsigned long));
	ft_putstr(value);
	length = ft_strlen(value);
	free(value);
	return (length);
}

int	ft_get_hex(va_list args, char c)
{
	int		length;
	char	*value;

	value = ft_unsigned_to_hex(va_arg(args, unsigned int), c);
	ft_putstr(value);
	length = ft_strlen(value);
	free(value);
	return (length);
}
