/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_init.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/24 12:23:59 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/25 15:37:36 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	philo_init(t_master *master, t_philo *philo, int i)
{
	philo->params = master->params;
	philo->mutex = master->mutex;
	philo->eat_count = 0;
	philo->last_meal_time = get_current_time();
	philo->id = i + 1;
	philo->l_fork = &master->mutex->forks[i];
	if (i == 0)
		philo->r_fork = &master->mutex->forks[master->params->n_philo - 1];
	else
		philo->r_fork = &master->mutex->forks[i - 1];
	philo->meals_reached = false;
}

bool	sim_init(t_master *master)
{
	int	i;

	i = 0;
	master->philo = malloc (sizeof(t_philo) * master->params->n_philo);
	if (!master->philo)
		return (1);
	while (i < master->params->n_philo)
	{
		philo_init(master, &master->philo[i], i);
		i++;
	}
	master->params->start_time = get_current_time();
	return (0);
}
