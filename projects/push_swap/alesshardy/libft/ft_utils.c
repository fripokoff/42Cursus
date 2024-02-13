/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 12:04:23 by apintus           #+#    #+#             */
/*   Updated: 2024/01/31 11:58:51 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_digit(long nbr, int base, int uppercase)
{
	size_t	len;
	char	*symbols;

	if (uppercase)
		symbols = "0123456789ABCDEF";
	else
		symbols = "0123456789abcdef";
	if (nbr < 0)
	{
		write(1, "-", 1);
		return (ft_digit(-nbr, base, uppercase) + 1);
	}
	else if (nbr < base)
		return (ft_putchar(symbols[nbr]));
	else
	{
		len = ft_digit(nbr / base, base, uppercase);
		return (len + ft_digit(nbr % base, base, uppercase));
	}
}

size_t	ft_digit_ptr(unsigned long nbr, unsigned long base)
{
	size_t	len;
	char	*symbols;

	symbols = "0123456789abcdef";
	if (nbr < base)
		return (ft_putchar(symbols[nbr]));
	else
	{
		len = ft_digit_ptr(nbr / base, base);
		return (len + ft_digit_ptr(nbr % base, base));
	}
}

size_t	ft_format_ptr(va_list args, size_t len)
{
	unsigned long	ptr;

	ptr = (unsigned long)va_arg(args, void *);
	if (ptr == 0)
		len += (ft_putstr("(nil)"));
	else
	{
		len += write(1, "0x", 2);
		len += ft_digit_ptr((unsigned long)ptr, 16);
	}
	return (len);
}

size_t	ft_format_str( va_list args, size_t len)
{
	char	*str;

	str = va_arg(args, char *);
	if (str == NULL)
		len += ft_putstr("(null)");
	else
		len += ft_putstr(str);
	return (len);
}
