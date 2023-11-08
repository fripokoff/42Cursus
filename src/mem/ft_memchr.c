/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 09:59:14 by kpires            #+#    #+#             */
/*   Updated: 2023/11/07 15:21:51 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

/*
#include <stdio.h>
#include <string.h>
int main(void)
{
	
    const char str[] = "ABCDEFG";
    const int chars[] = {'D', 'd'};
    for (size_t i = 0; i < sizeof chars / (sizeof chars[0]); ++i)
    {
        const int c = chars[i];   
        const char *ps = ft_memchr(str, c, strlen(str));
        ps ? printf ("character '%c'(%i) found: %s\n", c, c, ps)
           : printf ("character '%c'(%i) not found\n", c, c);
    }
    return 0;
}
*/