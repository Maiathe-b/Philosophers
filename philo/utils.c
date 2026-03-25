/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/18 16:23:01 by joao-maia         #+#    #+#             */
/*   Updated: 2026/03/25 16:23:13 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long	get_current_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL) == -1)
		return (-1);
	return (tv.tv_sec * 1000L + tv.tv_usec / 1000L);
}

bool	dead_check(t_philo *philo)
{
	bool	result;

	pthread_mutex_lock (&philo->mutex->death_mutex);
	result = philo->params->dead_flag;
	pthread_mutex_unlock (&philo->mutex->death_mutex);
	return (result);
}

void	philo_write(char *msg, t_philo *philo)
{
	long	time;

	pthread_mutex_lock (&philo->mutex->msg_mutex);
	if (!dead_check(philo))
	{
		pthread_mutex_unlock(&philo->mutex->msg_mutex);
		return ;
	}
	time = get_current_time() - philo->params->start_time;
	printf("%li %d %s\n", time, philo->id, msg);
	pthread_mutex_unlock(&philo->mutex->msg_mutex);
}

void	sleep_time(t_philo *philo, long ms)
{
	long	start;

	start = get_current_time();
	while (get_current_time() - start < ms)
	{
		if (!dead_check(philo))
			return ;
		usleep(500);
	}
}
