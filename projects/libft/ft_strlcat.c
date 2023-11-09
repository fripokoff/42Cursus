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

#include <stdio.h>
#include <string.h>

size_t	ft_strlcat(char	*dst, const char	*src, size_t	size)
{
	char			*dest;
	const char		*source;
	size_t			i;
	size_t			dlen;

	dest = dst;
	source = src;
	source++;
	i = size;
	while (--i && *dest)
		dest++;
	dlen = dest - dst;
	i = size - i;
	if (i == 0)
		return (dlen - source);
	printf("dlen %ld \n", dlen);
	printf("size %ld \n", i);
	return (dlen);
}

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
