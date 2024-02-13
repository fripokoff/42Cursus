/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: apintus <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 17:45:18 by apintus           #+#    #+#             */
/*   Updated: 2023/11/17 15:13:03 by apintus          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_int_len(long nbr)
{
	int	count;

	count = 0;
	if (nbr < 0)
	{
		count++;
		nbr = -nbr;
	}
	if (nbr == 0)
		count++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	int		len;
	int		i;
	char	*result;
	long	nbr;

	nbr = n;
	len = ft_int_len(nbr);
	result = malloc(sizeof(char) *(len + 1));
	if (!result)
		return (NULL);
	result[0] = 48;
	if (nbr < 0)
	{
		result[0] = '-';
		nbr = -nbr;
	}
	i = len - 1;
	while (nbr != 0)
	{
		result[i] = ((nbr % 10) + 48);
		nbr = nbr / 10;
		i--;
	}
	result[len] = '\0';
	return (result);
}

/*#include <stdio.h>

int	main(void)
{
	int	n;

	n = -94120;
	printf("%s\n", ft_itoa(n));
}*/
