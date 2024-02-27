/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 16:34:02 by apintus           #+#    #+#             */
/*   Updated: 2023/11/13 12:19:13 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;

	j = ft_strlen(src);
	i = 0;
	if (size > 0)
	{
		while (src[i] != '\0' && i < (size - 1))
		{
			dst[i] = src [i];
			i++;
		}
		dst[i] = '\0';
	}
	return (j);
}

/*#include <stdio.h>
int	main(void)
{
	char	src[] = "Abricots";
	char	dest[] = "peche";
	size_t	size;

	size = 9;
	printf("%ld | %s\n", ft_strlcpy(dest, src, size), dest);
	return (0);
}*/
