/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:41:12 by kpires            #+#    #+#             */
/*   Updated: 2023/11/09 13:09:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	char	*s;
	size_t	i;
	size_t	temp;
	size_t	srclen;
	size_t	dstlen;

	i = 0;
	temp = 0;
	srclen = ft_strlen(src);
	dstlen = ft_strlen(dst);
	s = (char *)src;
	if (size > dstlen)
		temp = srclen + dstlen;
	else
		temp = size + srclen;
	while (s[i] && (dstlen + 1) < size)
	{
		dst[dstlen] = s[i];
		dstlen++;
		i++;
	}
	dst[dstlen] = '\0';
	return (temp);
}
/*
#include <stdio.h>
#include <string.h>
int	main(void)
{
	char	dst[10];
	char	src[];
	int		len;

	src = "world!";
	dst = "Hello, ";
	len = ft_strlcat(dst, src, sizeof(dst));
	printf("La chaîne concaténée est : %s\n", dst);
	printf("La longueur de la chaîne concaténée est : %d\n", len);
	return (0);
}
*/
