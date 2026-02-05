/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kpires <kpires@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:22:10 by kpires            #+#    #+#             */
/*   Updated: 2025/02/13 14:57:49 by kpires           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <unistd.h>

struct				s_philo
{
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	pthread_t		thread;
	int				id;
	int				start;
	struct s_table	*table;
	int				last_meal;
	int				total_meal;
};

struct				s_table
{
	char			**argv;
	int				argc;
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				nb_meals;
	struct s_philo	*philo;
	int				start_time;
	int				fail;
	int				died;
	pthread_mutex_t	*forks;
	pthread_mutex_t	lock;
	int				lock_init;
};

int					ft_init(int argc, char **argv, struct s_table *table);
void				ft_create_threads(struct s_table *table, int i, int j);
void				ft_monitor(struct s_table *table);

void				*ft_onephilo(void *ptr);
int					ft_take_forks(struct s_philo *philo);
int					ft_eats(struct s_philo *philo);
void				ft_usleep(struct s_philo *philo, int delay);

int					ft_check_args(int argc, char **argv);
int					ft_atol(char *str);
int					ft_gettime(void);
void				ft_simul_print(struct s_philo *philo, char *str);
int					ft_read_death(struct s_philo *philo);
void				ft_frees(struct s_table *table, int i);

#endif
