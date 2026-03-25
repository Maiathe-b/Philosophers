/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:53:59 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/25 16:12:49 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	n_meals_reached(t_master *master)
{
	int	i;

	i = 0;
	pthread_mutex_lock(&master->mutex->eat_mutex);
	while (i < master->params->n_philo)
	{
		if (master->philo[i].meals_reached == false)
			break ;
		i++;
	}
	if (i == master->params->n_philo)
	{
		pthread_mutex_lock(&master->mutex->death_mutex);
		master->params->dead_flag = 0;
		pthread_mutex_unlock(&master->mutex->death_mutex);
		pthread_mutex_unlock(&master->mutex->eat_mutex);
		return (true);
	}
	pthread_mutex_unlock(&master->mutex->eat_mutex);
	return (false);
}

void	death_util(t_master *master, int i)
{
	pthread_mutex_lock(&master->mutex->death_mutex);
	master->params->dead_flag = 0;
	pthread_mutex_lock(&master->mutex->msg_mutex);
	printf("%ld %d %s\n", get_current_time() - master->params->start_time, \
master->philo[i].id, DIED_MSG);
	pthread_mutex_unlock(&master->mutex->eat_mutex);
	pthread_mutex_unlock(&master->mutex->death_mutex);
	pthread_mutex_unlock(&master->mutex->msg_mutex);
}

bool	philo_death(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->params->n_philo)
	{
		pthread_mutex_lock(&master->mutex->eat_mutex);
		if (!master->philo[i].meals_reached)
		{
			if (get_current_time() - master->philo[i].last_meal_time > \
master->params->delta_death)
			{
				death_util(master, i);
				return (true);
			}
		}
		pthread_mutex_unlock(&master->mutex->eat_mutex);
		i++;
	}
	return (false);
}

void	monitor(t_master *master)
{
	while (1)
	{
		if (master->params->_n_meals != -1)
		{
			if (n_meals_reached(master))
				return ;
		}
		if (philo_death(master))
			return ;
		usleep(500);
	}
}
