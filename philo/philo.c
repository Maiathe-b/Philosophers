/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:37 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/17 15:53:27 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_master(t_master *master)
{
	master = malloc(sizeof(t_master));
	memset(master, 0, sizeof(t_master));
	master->params = malloc(sizeof(t_params));
}

int	main(int argc, char **argv)
{
	t_master	*master;

	init_master(master);
	if (ft_parsing(argc, argv, master->params))
	{
		printf("%d", master->params->n_philo);
		printf("%ld", master->params->delta_death);
		printf("%ld", master->params->delta_eat);
		printf("%ld", master->params->delta_sleep);
	}
	free (master);
}