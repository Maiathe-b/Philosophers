/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/05 12:01:12 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/24 15:27:36 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	fork_destroy(t_master *master)
{
	int	i;

	i = 0;
	while (&master->mutex->forks[i])
	{
		pthread_mutex_destroy(&master->mutex->forks[i]);
		i++;
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
			fork_destroy(master);
			printf("MUTEX ERROR\n");
			return (1);
		}
		i++;
	}
	return (0);
}

bool	mutex_util(t_master *master)
{
	if (pthread_mutex_init(&master->mutex->death_mutex, NULL))
	{
		printf("MUTEX ERROR\n");
		return (1);
	}
	if (pthread_mutex_init(&master->mutex->eat_mutex, NULL))
	{
		printf("MUTEX ERROR\n");
		return (1);
	}
	if (pthread_mutex_init(&master->mutex->msg_mutex, NULL))
	{
		printf("MUTEX ERROR\n");
		return (1);
	}
	return (0);
}

bool	init_mutex(t_master *master)
{
	int	i;

	i = 0;
	master->mutex->forks = malloc(sizeof(pthread_mutex_t) * master->params->n_philo);
	if (!master->mutex->forks)
	{
		return (1);
	}
	if (fork_init(master))
		return (1);
	if (mutex_util(master))
		return (1);
	return (0);	
}