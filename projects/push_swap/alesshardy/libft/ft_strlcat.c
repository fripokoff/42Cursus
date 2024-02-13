/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:53:56 by apintus           #+#    #+#             */
/*   Updated: 2023/11/17 12:57:00 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	tdst;
	size_t	tsrc;

	if ((!dst || !src) && (!size))
		return (0);
	tdst = ft_strlen(dst);
	tsrc = ft_strlen(src);
	j = tdst;
	i = 0;
	if (tdst < size - 1 && size > 0)
	{
		while (src[i] && tdst + i < size - 1)
		{
			dst[j] = src[i];
			i++;
			j++;
		}
		dst[j] = '\0';
	}
	if (tdst >= size)
		tdst = size;
	return (tdst + tsrc);
}

/*#include <stdio.h>
int   main(void)
{
	char    src[] = "Abricots";
	char    dst[] = "Pomme";
	int     size;

	size = 10;
	printf("%ld | %s\n", ft_strlcat(dst, src, size), dst);
}*/
