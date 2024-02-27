/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:47:04 by apintus           #+#    #+#             */
/*   Updated: 2023/11/22 12:31:43 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)s;
	while (n > 0)
	{
		if (*str == (unsigned char)c)
			return (str);
		str++;
		n--;
	}
	return (NULL);
}

/*#include <stdio.h>
#include <string.h>
int     main(void)
{
        const char s[] = "peche";
        char    c;
	size_t	n;
        const char *result;

        c = 'e';
	n = 5;
        result = ft_memchr(s, c, n);
        if (result != NULL)
                printf("'%c' trouver a : %p\n", c, result);
        else
                printf("'%c' pas trouver", c);
}*/
