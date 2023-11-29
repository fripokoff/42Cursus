/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:28:37 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 17:30:29 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void	*destination, const void	*source, size_t num )
{
	char		*d;
	const char	*s;

	if (destination == source || num == 0)
		return (destination);
	if (!destination && !source)
		return (0);
	s = (const char *)source;
	d = (char *)destination;
	while (num--)
		d[num] = s[num];
	return (destination);
}

/*
** #include <stdio.h>
** 
** int main() {
**   char dst[10] = "hello 42";
**   const char src[100] = "hello 42";
**  	printf("dst = %s\n", dst);
**   ft_memcpy(dst, src, strlen(src));
**   printf("dst = %s\n", dst);
**   return 0;
** }
*/