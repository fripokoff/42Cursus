/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:13:54 by kpires            #+#    #+#             */
/*   Updated: 2024/01/24 12:26:54 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printchar(int c, int *b)
{
	write(1, &c, 1);
	if (b)
		*b = *b + 1;
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	printf_length;
	int	b;

	b = 0;
	printf_length = 0;
	if (format == 'c')
		printf_length += ft_printchar(va_arg(args, int), 0);
	else if (format == 'd' || format == 'i')
		printf_length += ft_putnbr(va_arg(args, int), &b);
	else if (format == 's')
		printf_length += ft_print_str(va_arg(args, char *));
	else if (format == 'u')
		printf_length += ft_putnbr_unsigned((unsigned int)va_arg(args,
					unsigned int), &b);
	else if (format == 'x' || format == 'X')
		printf_length += ft_put_hex(va_arg(args, unsigned int), format, &b);
	else if (format == 'p')
		printf_length += ft_putptr(va_arg(args,
					size_t), &b);
	else if (format == '%')
		printf_length += ft_printchar('%', 0);
	return (printf_length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printf_length;

	i = 0;
	printf_length = 0;
	if (!format)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printf_length += ft_format(args, format[i]);
		}
		else
			printf_length += ft_printchar(format[i], 0);
		i++;
	}
	va_end(args);
	return (printf_length);
}
