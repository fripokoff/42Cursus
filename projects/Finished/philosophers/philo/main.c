/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:21:32 by kpires            #+#    #+#             */
/*   Updated: 2025/02/13 13:15:05 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	struct s_table	table;

	if (ft_init(argc, argv, &table) == 1)
		return (1);
	if (table.nb_philo == 1)
	{
		pthread_mutex_lock(&table.lock);
		table.start_time = ft_gettime();
		table.philo[0].last_meal = table.start_time;
		if (pthread_create(&table.philo[0].thread, NULL, \
			&ft_onephilo, &table.philo[0]) != 0)
			return ((void)printf("philo: Error pthread"), \
				(void)ft_frees(&table, table.nb_philo - 1), 1);
		pthread_mutex_unlock(&table.lock);
		ft_monitor(&table);
		pthread_join(table.philo[0].thread, NULL);
	}
	else
		ft_create_threads(&table, 0, 0);
	ft_frees(&table, table.nb_philo - 1);
	if (table.fail == 1)
		return (1);
	return (0);
}
