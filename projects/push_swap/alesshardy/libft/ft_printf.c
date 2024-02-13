/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <apintus@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 10:39:53 by apintus           #+#    #+#             */
/*   Updated: 2024/01/31 11:58:08 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_format(char c, va_list args)
{
	size_t	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(args, int));
	else if (c == 's')
		len += ft_format_str(args, len);
	else if (c == 'd' || c == 'i')
		len += ft_digit((long)va_arg(args, int), 10, 0);
	else if (c == 'x')
		len += ft_digit((long)va_arg(args, unsigned int), 16, 0);
	else if (c == 'X')
		len += ft_digit((long)va_arg(args, unsigned int), 16, 1);
	else if (c == 'p')
		len += ft_format_ptr(args, len);
	else if (c == 'u')
		len += ft_digit((long)va_arg(args, unsigned int), 10, 0);
	else if (c == '%')
		len += write(1, "%", 1);
	return (len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	size_t	len;

	if (!str)
		return (-1);
	va_start(args, str);
	len = 0;
	while (*str)
	{
		if (*str == '%')
			len += ft_format(*(++str), args);
		else
			len += write(1, str, 1);
		++str;
	}
	va_end(args);
	return (len);
}

/*#include <limits.h>

int     main(void)
{
        int     count_ft;
        int     count_std;

        ft_printf("%p, %p", (void *)LONG_MIN, (void *)LONG_MAX);
        printf("\n%p, %p\n", (void *)LONG_MIN, (void *)LONG_MAX);

        count_ft = ft_printf("");
        count_std = printf("Char: %c\n", 'A');
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        char *str = "Hello, World!";
        count_ft = ft_printf("String: %s\n", str);
        count_std = printf("String: %s\n", str);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        int num = -12345;
        count_ft = ft_printf("Decimal: %d\n", num);
        count_std = printf("Decimal: %d\n", num);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        unsigned int hex_num = 0xABCD;
        count_ft = ft_printf("Hexadecimal: %x\n", hex_num);
        count_std = printf("Hexadecimal: %x\n", hex_num);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        void *ptr = (void *)0x12345678;
        count_ft = ft_printf("Pointer: %p\n", ptr);
        count_std = printf("Pointer: %p\n", ptr);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        unsigned int unsigned_num = 67890;
        count_ft = ft_printf("Unsigned: %u\n", unsigned_num);
        count_std = printf("Unsigned: %u\n", unsigned_num);
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        count_ft = ft_printf("Percentage: %%\n");
        count_std = printf("Percentage: %%\n");
        printf("Chars written by ft_printf: %d, Chars written by printf: %d\n",
                count_ft, count_std);

        return (0);
}*/
