/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 12:30:05 by apintus           #+#    #+#             */
/*   Updated: 2023/11/17 13:54:17 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*#include <stdio.h>
#include <strings.h>*/
#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	unsigned char	*dest;
	size_t			i;

	dest = s;
	i = 0;
	while (i < n)
	{
		*dest = 0;
		dest++;
		i++;
	}
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
	bzero(array, size);
	len = 0;
	while (len < 5)
	{
		printf("%d ", array[len]);
		len++;
	}
	printf("\n");
	return 0;
}*/
