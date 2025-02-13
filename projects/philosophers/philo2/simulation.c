/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 11:38:52 by kpires            #+#    #+#             */
/*   Updated: 2025/02/13 18:01:06 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_nbmeals(struct s_table *table)
{
	int	i;

	i = 0;
	if (table->nb_meals == -1)
		return (0);
	while (i < table->nb_philo)
	{
		if (table->philo[i].total_meal < table->nb_meals)
			return (0);
		i++;
	}
	table->died = 1;
	printf("philo: All philos have eaten %d time\n", table->nb_meals);
	pthread_mutex_unlock(&table->lock);
	return (1);
}

static void	ft_simulation(struct s_philo *philo)
{
	while (777)
	{
		if (ft_read_death(philo) == 1)
			return ;
		if (ft_take_forks(philo) == 1)
			return ;
		if (ft_eats(philo) == 1)
			return ;
		ft_simul_print(philo, "is sleeping");
		ft_usleep(philo, philo->table->time_sleep);
		if (ft_read_death(philo) == 1)
			return ;
		ft_simul_print(philo, "is thinking");
	}
}

static void	*ft_routine(void *ptr)
{
	struct s_philo	*philo;
	int				local_fail;

	philo = (struct s_philo *)ptr;
	pthread_mutex_lock(&philo->table->lock);
	local_fail = philo->table->fail;
	pthread_mutex_unlock(&philo->table->lock);
	if (local_fail == 1)
		return (0);
	if (philo->id % 2 == 0)
		ft_usleep(philo, philo->table->time_eat);
	ft_simulation(philo);
	return (0);
}

void	ft_monitor(struct s_table *table)
{
	int	i;

	if (table->fail == 1)
		return ;
	while (1)
	{
		pthread_mutex_lock(&table->lock);
		i = 0;
		while (i < table->nb_philo)
		{
			if (ft_gettime() - table->philo[i].last_meal > table->time_die)
			{
				table->died = 1;
				printf("%d %d died\n", ft_gettime() - table->start_time, i + 1);
				pthread_mutex_unlock(&table->lock);
				return ;
			}
			i++;
		}
		if (ft_check_nbmeals(table) == 1)
			return ;
		pthread_mutex_unlock(&table->lock);
		usleep(5000);
	}
}

void	ft_create_threads(struct s_table *table, int i, int j)
{
	pthread_mutex_lock(&table->lock);
	while (i < table->nb_philo)
	{
		table->start_time = ft_gettime();
		table->philo[i].last_meal = table->start_time;
		if (pthread_create(&table->philo[i].thread, NULL, \
			&ft_routine, &table->philo[i]) != 0)
		{
			table->fail = 1;
			printf("philo: Error insufficient resources to create thread\n");
			pthread_mutex_unlock(&table->lock);
			while (--i >= 0)
				pthread_join(table->philo[i].thread, NULL);
			return ;
		}
		i++;
	}
	pthread_mutex_unlock(&table->lock);
	ft_monitor(table);
	while (j < i)
	{
		if (pthread_join(table->philo[j].thread, NULL) != 0)
			printf("philo: Error failed to join thread\n");
		j++;
	}
}
