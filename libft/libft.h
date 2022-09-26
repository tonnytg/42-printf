/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: antthoma <antthoma@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/14 22:43:27 by antthoma          #+#    #+#             */
/*   Updated: 2022/07/11 14:24:40 by antthoma         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>

int     is_negative(int n);
char    *ft_itoa(int n);
int     ft_len_digits(unsigned int n);
void    ft_print_unsig_numb(unsigned long nb);
int     ft_putchar_fd(int c, int fd);
int     ft_putnbr(int nb);
int     ft_putstr(char *str);
char    *ft_strdup(const char *src);
size_t  ft_strlen(const char *s);
size_t	ft_calc_size_base(unsigned long int n, int base);
char	*ft_unsigned_to_ascii(unsigned int n);
char	*ft_unsigned_to_hex(unsigned long long n, char flag);


#endif
