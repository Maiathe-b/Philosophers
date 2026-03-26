/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42lisboa.com>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:01:12 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/26 00:19:45 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_destroy(t_master *master, int i)
{
	while (i >= 0)
	{
		pthread_mutex_destroy(&master->mutex->forks[i]);
		i--;
	}
}

bool	fork_init(t_master *master)
{
	int	i;

	i = 0;
	while (i < master->params->n_philo)
	{
		if (pthread_mutex_init(&master->mutex->forks[i], NULL))
		{
			fork_destroy(master, i);
			printf("MUTEX ERROR\n");
			return (true);
		}
		i++;
	}
	return (false);
}

bool	mutex_util(t_master *master)
{
	if (pthread_mutex_init(&master->mutex->death_mutex, NULL) || \
pthread_mutex_init(&master->mutex->eat_mutex, NULL) || \
pthread_mutex_init(&master->mutex->msg_mutex, NULL))
	{
		printf("MUTEX ERROR\n");
		return (true);
	}
	return (false);
}

bool	init_mutex(t_master *master)
{
	master->mutex->forks = malloc(sizeof(pthread_mutex_t) * \
master->params->n_philo);
	if (!master->mutex->forks)
		return (true);
	if (fork_init(master))
		return (true);
	if (mutex_util(master))
		return (true);
	return (false);
}
