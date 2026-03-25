/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:37 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/25 14:40:00 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_master *master)
{
	int	i;

	i = 0;
	if ((master)->mutex)
	{
		if ((master)->mutex->forks)
		{
			while (i < (master)->params->n_philo)
			{
				pthread_mutex_destroy (&master->mutex->forks[i]);
				i++;
			}
		}
		pthread_mutex_destroy (&master->mutex->death_mutex);
		pthread_mutex_destroy (&master->mutex->eat_mutex);
		pthread_mutex_destroy (&master->mutex->msg_mutex);
		free (master->mutex->forks);
		free (master->mutex);
	}
}

void	free_master(t_master **master)
{
	destroy_mutex(*master);
	if ((*master)->params)
		free ((*master)->params);
	if ((*master)->philo)
		free ((*master)->philo);
	free (*master);
}

int	init_master(t_master *master)
{
	master->params = malloc(sizeof(t_params));
	if (!master->params)
		return 0;
	memset(master->params, 0, sizeof(t_params));
	master->mutex = malloc(sizeof(t_mutex));
	if (!master->mutex)
		return 0;
	memset(master->mutex, 0, sizeof(t_mutex));
	master->philo = NULL;
	return (1);
}

void	start_sim(t_master *master)
{
	int	i;
	
	i = 0;
	while (i < master->params->n_philo)
	{
		pthread_create(&master->philo[i].thread, NULL, philo_loop, &master->philo[i]);
		i++;
	}
	monitor(master);
	i = 0;
	while (i < master->params->n_philo)
	{
		pthread_join(master->philo[i].thread, NULL);
		i++;
	}
}

int	main(int argc, char **argv)
{
	t_master	*master;

	master = malloc(sizeof(t_master));
	memset(master, 0, sizeof(t_master));
	if (!init_master(master))
		return (1);
	if (!ft_parsing(argc, argv, master->params))
	{
		free_master(&master);
		return (1);
	}
	if (master->params->n_philo == 1)
	{
		printf("0 1 has taken a fork\n");
		usleep(master->params->delta_death * 1000);
		printf("%li 1 died \n", master->params->delta_death);
		return (0);
	}
	if (init_mutex(master) || sim_init(master))
		return (1);
	start_sim(master);
	free_master(&master);
}
