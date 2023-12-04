/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:41:12 by kpires            #+#    #+#             */
/*   Updated: 2023/11/30 12:14:40 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (size == 0)
		return (ft_strlen(src));
	if (size < ft_strlen(dst))
		return (ft_strlen(src) + size);
	i = ft_strlen(dst);
	while (src[j] && i + j + 1 < size)
	{
		dst[i + j] = src[j];
		j++;
	}
	dst[i + j] = '\0';
	return (i + ft_strlen(src));
}
/*
** #include <stdio.h>
** #include <string.h>
** int	main(void)
** {
** 	char	dst[10];
** 	char	src[];
** 	int		len;
** 
** 	src = "world!";
** 	dst = "Hello, ";
** 	len = ft_strlcat(dst, src, sizeof(dst));
** 	printf("La chaîne concaténée est : %s\n", dst);
** 	printf("La longueur de la chaîne concaténée est : %d\n", len);
** 	return (0);
** }
*/
