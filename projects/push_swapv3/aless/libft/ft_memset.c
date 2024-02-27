/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 11:21:12 by apintus           #+#    #+#             */
/*   Updated: 2023/11/17 13:05:54 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <string.h>*/
#include "libft.h"

void	*ft_memset(void *s, int c, size_t n)
{
	size_t			i;
	unsigned char	*str;

	str = (unsigned char *) s;
	i = 0;
	while (i < n)
	{
		*str = (unsigned char)c;
		str++;
		i++;
	}
	return (s);
}

/*int	main(void)
{
	int	array[] = { 56, 89, 75, 69, 24 };
	size_t	size;
	int	len;

	len = 0;
	size = sizeof( int ) * 5;

	while (len < 5)
	{
		printf("%d ", array[len]);
		len++;
	}
	printf("\n");
	ft_memset(array, 0, size);
	len = 0;
	while (len < 5)
	{
		printf("%d ", array[len]);
		len++;
	}
	printf("\n");
	return 0;
}*/
