/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:00 by kpires            #+#    #+#             */
/*   Updated: 2024/02/26 00:03:51 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char	*nptr, int	*check_limits)
{
	long long int	val;
	int				signe;
	int				i;

	val = 0;
	signe = 1;
	i = 0;
	while (nptr[i] != '\0' && (nptr[i] == ' ' || (nptr[i] >= '\t' && nptr[i] <= '\r')))
		i++;
	if (nptr[i] != '\0' && (nptr[i] == '-' || nptr[i] == '+'))
	{
		if (i > 0 && (nptr[i - 1] != ' ' || nptr[i + 1] == '\0'))
			return (*check_limits = 1);
		if (nptr[i] == '-')
			signe = -1;
		if (nptr[i + 1])
			i++;
		else
			return (*check_limits = 1);
	}
	while (nptr[i] != '\0')
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (*check_limits = 1);
		
		if ((signe > 0 && val > (INT_MAX - (nptr[i] - '0')) / 10)
		|| (signe < 0 && val < (INT_MIN + (nptr[i] - '0')) / 10))
			return (*check_limits = 1);
		val = val * 10 + signe * (nptr[i] - '0');
		i++;
	}
	printf("val #[%lli]: \n", val);
	return (val);
}

// "+456 +321"