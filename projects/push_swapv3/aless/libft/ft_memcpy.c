/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 15:06:11 by apintus           #+#    #+#             */
/*   Updated: 2023/11/20 12:27:37 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*tsrc;
	unsigned char	*tdest;

	if (!dest && !src)
		return (NULL);
	tsrc = (unsigned char *) src;
	tdest = (unsigned char *) dest;
	i = 0;
	while (i < n)
	{
		*(char *)tdest = *(char *)tsrc;
		tdest++;
		tsrc++;
		i++;
	}
	return (dest);
}

/*int	main(void)
{
	char dest[4];
	char src[] = "peche abricot";
	ft_memcpy(dest, src, 6);
	printf("%s\n",dest);
	return (0);
}*/
