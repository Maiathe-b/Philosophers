/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:40 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/05 17:52:44 by jomaia           ###   ########.fr       */
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

typedef struct	s_philo
{
	t_mutex	*forks;
}	t_philo;

typedef struct	s_params
{
	int	n_philo;
	long	delta_death;
	long	delta_eat;
	long	delta_sleep;
	long	_n_meals;
}	t_params;

typedef	struct s_waiter
{
	pthread_mutex_t	*forks;
	pthread_mutex_t	*philo;
}	t_waiter;

typedef struct s_master
{
	t_params	*params;
}	t_master;


int		ft_atoi(const char *nptr);
bool	ft_parsing(int argc, char **argv, t_params *params);

#endif