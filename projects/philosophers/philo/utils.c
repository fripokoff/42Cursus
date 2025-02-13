/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:23:48 by kpires            #+#    #+#             */
/*   Updated: 2025/02/13 17:59:00 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_frees(struct s_table *table, int i)
{
	if (table->forks)
	{
		while (i >= 0)
		{
			pthread_mutex_destroy(&table->forks[i]);
			i--;
		}
		free(table->forks);
		table->forks = NULL;
	}
	if (table->philo)
		free(table->philo);
	if (table->lock_init)
		pthread_mutex_destroy(&table->lock);
}

int	ft_gettime(void)
{
	struct timeval	time;

	if (gettimeofday(&time, NULL) == -1)
	{
		printf("philo: Error ft_gettimeofday");
		return (0);
	}
	return ((long long)(time.tv_sec * 1000) + (long long)(time.tv_usec / 1000));
}

void	ft_simul_print(struct s_philo *philo, char *str)
{
	int	time;

	pthread_mutex_lock(&philo->table->lock);
	if (philo->table->died == 0)
	{
		time = ft_gettime() - philo->table->start_time;
		printf("%d %d %s\n", time, philo->id, str);
	}
	pthread_mutex_unlock(&philo->table->lock);
}

void	ft_usleep(struct s_philo *philo, int delay)
{
	int	start;

	start = ft_gettime();
	while (ft_gettime() - start < delay)
	{
		if (ft_read_death(philo) == 1)
			return ;
		usleep(500);
	}
}
