/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:00 by kpires            #+#    #+#             */
/*   Updated: 2023/11/09 11:14:59 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_check(int signe, long long int check, long long int val)
{
	if (val > check && signe < 0)
		return (0);
	if (val < check && signe > 0)
		return (-1);
	return (val);
}

int	ft_atoi(const char	*nptr )
{
	int				i;
	long long int	val;
	int				signe;
	long long int	check;

	i = 0;
	val = 0;
	signe = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r'))
		i++;
	if (nptr[i] == '-' || nptr[i] == '+' )
	{
		if (nptr[i] == '-')
			signe = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		check = val;
		val = val * 10 + signe * (nptr[i] - '0');
		ft_check(signe, check, val);
		i++;
	}
	return (val);
}

/*
#include <stdlib.h>
#include <stdio.h>
int	main(int ac, char **av)
{
	(void)ac;
	printf("atoi = %d \n",atoi(av[1]));
	printf("ft_atoi = %d \n",ft_atoi(av[1]));
}
*/