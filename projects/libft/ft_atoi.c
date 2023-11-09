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

int	ft_atoi(const char	*nptr )
{
	int	i;
	int	val;
	int	minus;

	i = 0;
	val = 0;
	minus = 1;
	while (nptr[i] == ' ' || (nptr[i] >= '\r' && nptr[i] <= '\t'))
		i++;
	while (nptr[i] == '-' || nptr[i] == '+' )
	{
		if (minus > 1 || minus < 0)
			return (0);
		if (nptr[i] == '-')
			minus = -1;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		val = val * 10 + (nptr[i] - '0');
		i++;
	}
	return (val * minus);
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