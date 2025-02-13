/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   state.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 14:23:12 by kpires            #+#    #+#             */
/*   Updated: 2025/02/13 18:01:56 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_eats(struct s_philo *philo)
{
	pthread_mutex_lock(&philo->table->lock);
	if (philo->table->died)
	{
		pthread_mutex_unlock(&philo->table->lock);
		pthread_mutex_unlock(philo->l_fork);
		pthread_mutex_unlock(philo->r_fork);
		return (1);
	}
	philo->last_meal = ft_gettime();
	philo->total_meal++;
	pthread_mutex_unlock(&philo->table->lock);
	ft_simul_print(philo, "is eating");
	ft_usleep(philo, philo->table->time_eat);
	pthread_mutex_unlock(philo->l_fork);
	pthread_mutex_unlock(philo->r_fork);
	return (ft_read_death(philo));
}

int	ft_take_forks(struct s_philo *philo)
{
	if (ft_read_death(philo) == 1)
		return (1);
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->l_fork);
		ft_simul_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->r_fork);
		ft_simul_print(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(philo->r_fork);
		ft_simul_print(philo, "has taken a fork");
		pthread_mutex_lock(philo->l_fork);
		ft_simul_print(philo, "has taken a fork");
	}
	if (ft_read_death(philo) == 1)
	{
		pthread_mutex_unlock(philo->r_fork);
		pthread_mutex_unlock(philo->l_fork);
		return (1);
	}
	return (0);
}

int	ft_read_death(struct s_philo *philo)
{
	int	died;

	died = 0;
	pthread_mutex_lock(&philo->table->lock);
	died = philo->table->died;
	pthread_mutex_unlock(&philo->table->lock);
	return (died);
}

void	*ft_onephilo(void *ptr)
{
	struct s_philo	*philo;

	philo = (struct s_philo *)ptr;
	pthread_mutex_lock(philo->l_fork);
	ft_simul_print(philo, "has taken a fork");
	ft_usleep(philo, philo->table->time_die * 2);
	pthread_mutex_unlock(philo->l_fork);
	return (0);
}
