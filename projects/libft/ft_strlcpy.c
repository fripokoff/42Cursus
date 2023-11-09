/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:19:18 by kpires            #+#    #+#             */
/*   Updated: 2023/11/09 13:21:11 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char	*dst, const char	*src, size_t	size)
{
	unsigned int	i;

	i = 0;
	if (!dst || !src)
		return (0);
	if (i < size)
	{
		while (src[i])
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	while (src[i])
		i++;
	return (i);
}

#include <stdio.h>
#include <string.h>

int main()
{
	char var1[6] = "stuff";
	char var2[7] = "world!";
	ft_strlcpy(var1, var2, sizeof(var2));
	printf("hello %s", var1);
	return (0);
}

