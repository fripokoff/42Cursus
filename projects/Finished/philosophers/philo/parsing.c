/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 11:54:55 by kpires            #+#    #+#             */
/*   Updated: 2025/02/13 20:24:21 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atol(char *str)
{
	int				i;
	long long int	result;
	long long int	sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == 32)
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		i++;
		if ((result > INT_MAX) || (result * sign < INT_MIN))
			return (0);
	}
	return ((int)result * (int)sign);
}

int	ft_check_args(int argc, char **argv)
{
	int	i;
	int	j;

	if (argc < 5 || argc > 6)
	{
		printf("philo: Usage: ./philo [number_of_philo] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep] <number_of_simulation>\n");
		printf("Required:[value] ~ Optional:<value>\n");
		return (1);
	}
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (!(argv[i][j] >= '0' && argv[i][j] <= '9') && argv[i][j] != '+')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}
