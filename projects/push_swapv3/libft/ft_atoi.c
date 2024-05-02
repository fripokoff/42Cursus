/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:00 by kpires            #+#    #+#             */
/*   Updated: 2024/05/02 15:28:44 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

int	ft_atoi(const char	*nptr, int *error_limits)
{
	long long int	val;
	int				signe;

	*error_limits = 0;
	val = 0;
	signe = 1;
	while (*nptr == ' ' || (*nptr >= '\t' && *nptr <= '\r'))
		nptr++;
	if (*nptr == '-' || *nptr == '+' )
	{
		if (*nptr == '-')
			signe = -1;
		nptr++;
	}
	while (*nptr >= '0' && *nptr <= '9')
	{
		val = val * 10 + signe * (*nptr - '0');
		if (val > INT_MAX || val < INT_MIN
		|| (!val && (*nptr == '-' || *nptr == '+')))
			*error_limits = 1;
		nptr++;
	}
	if (*nptr && *nptr != ' ' && !(*nptr >= '0' && *nptr <= '9'))
		*error_limits = 1;
	return (val);
}
