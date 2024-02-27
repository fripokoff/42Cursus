/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:20:59 by apintus           #+#    #+#             */
/*   Updated: 2023/11/16 12:27:20 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*c1;
	unsigned char	*c2;
	size_t			i;

	c1 = (unsigned char *)s1;
	c2 = (unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (c1[i] == c2[i] && c1[i] != '\0' && c2[i] != '\0' && i < n -1)
		i++;
	return (c1[i] - c2[i]);
}

/*#include <stdio.h>
#include <string.h>

int	main(void)
{
	char s1[] = "test\0";
	char s2[] = "test\200";
	size_t	n;

	n = 6;
	printf("%d\n" , ft_strncmp(s1, s2, n));
	printf("%d\n" , strncmp(s1, s2, n));
	return (0);
}*/
