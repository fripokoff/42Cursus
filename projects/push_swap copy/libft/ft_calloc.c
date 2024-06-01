/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:24:41 by kpires            #+#    #+#             */
/*   Updated: 2023/11/29 17:10:00 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc( size_t nmemb, size_t size )
{
	size_t	total_size;
	void	*ptr;

	total_size = nmemb * size;
	if (nmemb && size && nmemb > 2147483647 / size)
		return (NULL);
	ptr = malloc(total_size);
	if (!ptr)
		return (NULL);
	ft_bzero(ptr, total_size);
	return (ptr);
}

/*
** #include <stdlib.h>
** #include <unistd.h>
** 
** void	*ft_memset(void *s, int c, size_t n)
** 
** {
** 	unsigned char	*str;
** 	size_t			i;
** 
** 	i = 0;
** 	str = (unsigned char *)s;
** 	while (i < n)
** 		str[i++] = (unsigned char)c;
** 	return (s);
** }
** 
** void	ft_bzero(void *s, size_t n)
** {
** 	ft_memset(s, '\0', n);
** }
** 
** int		main(void)
** {
** 	char	*str;
** 
** 	str = (char *)ft_calloc(30, 1);
** 	if (!str)
** 		write(1, "NULL", 4);
** 	else
** 		write(1, "OK", 2);
** return (0);
** }
*/