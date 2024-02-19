/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/19 11:19:58 by kpires            #+#    #+#             */
/*   Updated: 2024/02/19 11:19:58 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_isspace(char c, const char *d)
{
	if (d)
	{
		while (*d)
		{
			if (*d != ' ' || *d != '\t' || *d != '\n'
				|| *d != '\v' || *d != '\f' || *d != '\r')
				return (0);
			d++;
		}
		return (1);
	}
	else
		return (c == ' ' || c == '\t' || c == '\n'
			|| c == '\v' || c == '\f' || c == '\r');
}

long	check_syntax_and_atoi(char *str)
{
	long	result;
	int		sign;

	result = 0;
	sign = 1;
	while (ft_isspace(*str, NULL))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str == '0')
		str++;
	if (ft_strlen(str) > 11)
		return (0);
	while (*str)
	{
		if (!((*str >= '0' && *str <= '9')))
			return (0);
		result = result * 10 + *str - '0';
		str++;
	}
	return (result * sign);
}
