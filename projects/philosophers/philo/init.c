/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:42:16 by kpires            #+#    #+#             */
/*   Updated: 2025/02/13 15:01:41 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_create_philos(struct s_table *table)
{
	int	i;

	i = 0;
	table->philo = malloc(sizeof(struct s_philo) * \
			(unsigned long)table->nb_philo);
	if (table->philo == NULL)
		return ((void)printf("philo: Error malloc\n"), 1);
	while (i < table->nb_philo)
	{
		table->philo[i].id = i + 1;
		table->philo[i].table = table;
		table->philo[i].l_fork = &table->forks[i];
		if (table->nb_philo == 1)
			table->philo[i].r_fork = NULL;
		else
			table->philo[i].r_fork = &table->forks[(i + 1) % table->nb_philo];
		table->philo[i].last_meal = table->start_time;
		table->philo[i].total_meal = 0;
		i++;
	}
	return (0);
}

static int	ft_create_forks(struct s_table *table)
{
	int	i;

	i = 0;
	table->forks = malloc(sizeof(pthread_mutex_t) * (size_t)table->nb_philo);
	if (table->forks == NULL)
		return ((void)printf("philo: Error malloc\n"), 1);
	while (i < table->nb_philo)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			ft_frees(table, i - 1);
			return ((void)printf("philo: Error mutex\n"), 1);
		}
		i++;
	}
	if (ft_create_philos(table) == 1)
		return ((void)ft_frees(table, i - 1), 1);
	return (0);
}

static int	ft_fill(struct s_table *table, int argc, char **argv)
{
	table->fail = 0;
	table->argc = argc;
	table->argv = argv;
	table->nb_meals = -1;
	table->died = 0;
	table->start_time = 0;
	table->philo = NULL;
	table->forks = NULL;
	table->nb_philo = ft_atol(table->argv[1]);
	table->time_die = ft_atol(table->argv[2]);
	table->time_eat = ft_atol(table->argv[3]);
	table->time_sleep = ft_atol(table->argv[4]);
	table->lock_init = 0;
	if (table->nb_philo < 1 || table->time_die < 1 || table->time_eat < 1 \
		|| table->time_sleep < 1)
		return ((void)printf("philo: Invalid argument\n"), 1);
	if (table->argc == 6)
	{
		table->nb_meals = ft_atol(table->argv[5]);
		if (table->nb_meals < 1)
			return ((void)printf("philo: Invalid argument\n"), 1);
	}
	return (0);
}

int	ft_init(int argc, char **argv, struct s_table *table)
{
	if (argc < 5 || argc > 6)
	{
		printf("philo: Usage: ./philo [number_of_philo] [time_to_die]");
		printf(" [time_to_eat] [time_to_sleep] <number_of_simulation>\n");
		printf("Required:[value] ~ Optional:<value>\n");
		return (1);
	}
	if (ft_check_args(argc, argv) == 1)
		return ((void)printf("philo: Invalid argument\n"), 1);
	if (ft_fill(table, argc, argv) == 1)
		return (1);
	if (pthread_mutex_init(&table->lock, NULL) != 0)
		return ((void)printf("philo: Error mutex\n"), 1);
	table->lock_init = 1;
	if (ft_create_forks(table) == 1)
		return (1);
	return (0);
}
