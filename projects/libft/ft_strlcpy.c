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
	size_t	i;
	size_t	src_l;

	src_l = ft_strlen(src);
	if (size == 0)
		return (src_l);
	i = 0;
	while (src[i] && i < (size -1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (src_l);
}
/*
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
*/
