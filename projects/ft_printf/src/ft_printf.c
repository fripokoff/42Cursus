/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 12:13:54 by kpires            #+#    #+#             */
/*   Updated: 2023/12/04 14:36:45 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_printchar(int c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_format(va_list args, const char format)
{
	int	printf_length;

	printf_length = 0;
	if (format == 'c')
		printf_length += ft_printchar(va_arg(args, int));
	else if (format == 's')
		printf_length += ft_print_str(va_arg(args, char *));
	return (printf_length);
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		i;
	int		printf_length;

	i = 0;
	printf_length = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			printf_length += ft_format(args, format[i]);
		}
		else
			printf_length += ft_printchar(format[i]);
		i++;
	}
	va_end(args);
	return (printf_length);
}

