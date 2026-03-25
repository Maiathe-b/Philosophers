/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_loop.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 14:13:09 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/25 14:33:47 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	get_fork(t_philo *philo)
{
	if (philo->id % 2 != 0)
	{
		pthread_mutex_lock (philo->l_fork);
		philo_write(FORK_MSG, philo);
		pthread_mutex_lock (philo->r_fork);
		philo_write(FORK_MSG, philo);
		return ;
	}
	pthread_mutex_lock (philo->r_fork);
	philo_write(FORK_MSG, philo);
	pthread_mutex_lock (philo->l_fork);
	philo_write(FORK_MSG, philo);
	return ;
}

void	philo_eat(t_philo *philo)
{
	pthread_mutex_lock (&philo->mutex->eat_mutex);
	if (!philo->meals_reached)
	{
		get_fork(philo);
		philo_write (EAT_MSG, philo);
		philo->last_meal_time = get_current_time();
		philo->eat_count++;
		if (philo->eat_count == philo->params->_n_meals)
			philo->meals_reached = true;
		pthread_mutex_unlock (&philo->mutex->eat_mutex);
		sleep_time(philo, philo->params->delta_eat);
		pthread_mutex_unlock (philo->l_fork);
		pthread_mutex_unlock (philo->r_fork);
	}
	else
		pthread_mutex_unlock (&philo->mutex->eat_mutex);

}

void	philo_sleep(t_philo *philo)
{
	philo_write(SLEEP_MSG, philo);
	sleep_time(philo, philo->params->delta_sleep);
}

void	philo_thinks(t_philo *philo)
{
	philo_write(THINK_MSG, philo);
}

void	*philo_loop(void *philos)
{
	t_philo	*philo;

	philo = (t_philo *)philos;
	if (philo->id % 2 != 0)
		sleep_time(philo, 100);
	while (dead_check(philo))
	{
		philo_eat(philo);
		if (!dead_check(philo))
			break ;
		philo_sleep(philo);
		if (!dead_check(philo))
			break ;
		philo_thinks(philo);
	}
	return (NULL);
}