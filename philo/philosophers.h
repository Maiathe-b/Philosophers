/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-maia <joao-maia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 16:25:18 by jomaia            #+#    #+#             */
/*   Updated: 2026/01/07 15:02:27 by joao-maia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include "stdio.h"
# include "stdlib.h"
# include "pthread.h"
# include "unistd.h"
# include "sys/time.h"
# include "stdbool.h"

# define ERR_ARG_NBR "ERROR: invalid number of args\n"
# define ERR_INV_ARG "ERROR: invalid arg\n"
# define ERR_MUT "ERROR: Mutex creation failed\n"

# define FORK_TXT "has taken a fork"
# define EAT_TXT "is eating"
# define SLEEP_TXT "is sleeping"
# define THINK_TXT "is thinking"
# define DEAD_TXT "is dead"
# define IS_FULL 1
# define IS_HUNGRY 0

typedef struct s_mutex
{
	pthread_mutex_t *forks;
	
	pthread_mutex_t write_lock;
	pthread_mutex_t meal_lock;
	pthread_mutex_t death_lock;
}	t_mutex;

typedef struct s_info
{
	int		philo_count;
	bool	all_philos_alive;
	long	start_time;
	long	time_die;
	long	time_eat;
	long	time_sleep;
	long	eat_numb;
}	t_info;

int	ft_isdigit(int c);
int	ft_atoi(const char *nptr);

#endif