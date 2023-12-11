/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_functions.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user <user@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:43:52 by kpires            #+#    #+#             */
/*   Updated: 2023/12/11 14:10:54 by user             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_put_hex(unsigned int nbr, const char format, int *b)
{
	unsigned int	div;
	unsigned int	mod;

	div = nbr / 16;
	mod = nbr % 16;
	if (div)
		ft_put_hex(div, format, b);
	if (mod <= 9)
		mod = mod + '0';
	else
	{
		if (format == 'x')
			mod = mod - 10 + 'a';
		if (format == 'X')
			mod = mod - 10 + 'A';
	}
	ft_printchar((int)mod, b);
	if (!nbr && !b)
		return (1);
	return (*b);
}

int	ft_putptr(uintptr_t ptr, int *b)
{
	uintptr_t	div;
	uintptr_t	mod;

	if (!ptr)
		return (ft_printchar('0', b));
	div = ptr / 16;
	mod = ptr % 16;
	if (div)
		ft_putptr(div, b);
	if (mod <= 9)
		mod = mod + '0';
	else
		mod = mod - 10 + 'a';
	ft_printchar((int)mod, b);
	return (*b);
}

int	ft_putnbr(int nbr, int *b)
{
	int	div;
	int	mod;

	div = nbr / 10;
	mod = nbr % 10;
	if (div)
		ft_putnbr(div, b);
	if (nbr < 0)
	{
		mod = -mod;
		if (!div)
			ft_printchar('-', b);
	}
	mod = mod + '0';
	ft_printchar((int)mod, b);
	return (*b);
}

int	ft_putnbr_unsigned(unsigned int nbr, int *b)
{
	unsigned int	div;
	unsigned int	mod;

	div = nbr / 10;
	mod = nbr % 10;
	if (div)
		ft_putnbr_unsigned(div, b);
	mod = mod + '0';
	ft_printchar((int)mod, b);
	if (!nbr && !b)
		return (1);
	return (*b);
}

int	ft_print_str(char *str)
{
	int	i;

	i = 0;
	if (!str)
		str = "(null)";
	while (str[i])
		ft_printchar(str[i++], 0);
	return (i);
}
