/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:40 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/24 12:33:52 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include "unistd.h"
# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "sys/time.h"
# include "stdbool.h"
# include <string.h>

typedef struct	s_mutex
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	msg_mutex;
	pthread_mutex_t	eat_mutex;
	pthread_mutex_t	death_mutex;
}	t_mutex;


typedef struct	s_params
{
	int		n_philo;
	long	delta_death;
	long	delta_eat;
	long	delta_sleep;
	long	_n_meals;
	long	start_time;
	bool	dead_flag;
}	t_params;

typedef struct s_philo
{
	t_params		*params;
	t_mutex			*mutex;
	pthread_t		thread;
	pthread_mutex_t	*l_fork;
	pthread_mutex_t	*r_fork;
	long			last_meal_time;
	int				id;
	int				eat_count;
	int				philo_hunger;
}	t_philo;


typedef	struct s_waiter
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*philo;
}	t_waiter;

typedef struct s_master
{
	t_params	*params;
	t_mutex		*mutex;
	t_philo		*philo;
}	t_master;

void	sleep_time(t_master *master, long ms);
long	get_current_time(void);
int		ft_atoi(const char *nptr);
bool	ft_parsing(int argc, char **argv, t_params *params);
bool	sim_init(t_master *master);
bool	init_mutex(t_master *master);

#endif