/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fripok <fripok@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/28 12:16:42 by fripok            #+#    #+#             */
/*   Updated: 2023/11/28 15:09:52 by fripok           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_putnbr(int nbr, char *s, int *count)
{
	int	div;
	int	mod;

	div = nbr / 10;
	mod = nbr % 10;
	if (div)
		ft_putnbr(div, s, count);
	if (nbr < 0)
	{
		mod = -mod;
		if (!div)
		{
			s[*count] = '-' + 0;
			*count += 1;
		}
	}
	mod = mod + '0';
	s[*count] = mod;
	*count += 1;
	return (s);
}

static int	ft_putnbr_len(int nbr, int *count)
{
	int	div;

	div = nbr / 10;
	*count += 1;
	if (div)
		ft_putnbr_len(div, count);
	return (*count);
}

char	*ft_itoa(int n)
{
	char	*s;
	int		nbr_len;
	int		i;
	int		count;

	i = 0;
	count = 0;
	nbr_len = ft_putnbr_len(n, &i);
	if (n < 0)
		s = malloc(sizeof(char) * (nbr_len + 2));
	else
		s = malloc(sizeof(char) * (nbr_len + 1));
	if (!s)
		return (NULL);
	s = ft_putnbr(n, s, &count);
	s[count] = 0;
	return (s);
}
