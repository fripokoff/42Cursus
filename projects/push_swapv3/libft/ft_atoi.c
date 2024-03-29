/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 11:36:00 by kpires            #+#    #+#             */
/*   Updated: 2024/02/28 14:49:34 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char	*nptr, int *check_limits)
{
	long long int	val;
	int				signe;

	*check_limits = 0;
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
		if ((signe == 1 && val > (LLONG_MAX - (*nptr - '0')) / 10) ||
        (signe == -1 && val > ((LLONG_MIN + (*nptr - '0')) / -10)))
    {
        *check_limits = 1;
        break;
    }
		val = val * 10 + signe * (*nptr - '0');
		nptr++;
	}
	if (*nptr && *nptr != ' ' && !(*nptr >= '0' && *nptr <= '9'))
		*check_limits = 1;
	if (val > INT_MAX || val < INT_MIN)
		*check_limits = 1;
	return (val);
}
