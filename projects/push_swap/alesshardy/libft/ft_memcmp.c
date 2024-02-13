/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 14:46:10 by apintus           #+#    #+#             */
/*   Updated: 2023/11/21 12:44:15 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	i = 0;
	c1 = (unsigned char *) s1;
	c2 = (unsigned char *) s2;
	while (i < n)
	{
		if (c1[i] != c2[i])
			return (c1[i] - c2[i]);
		i++;
	}
	return (0);
}

/*#include <stdio.h>
#include <string.h>

int     main(void)
{
        const char s1[] = "abricots";
	const char s2[] = "abricot";
	size_t  n;

        n = 8;
        printf("%d\n" , ft_memcmp(s1, s2, n));
        printf("%d\n" , memcmp(s1, s2, n));
}*/
