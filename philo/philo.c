/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joao-maia <joao-maia@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:37 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/18 11:35:11 by joao-maia        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_master(t_master *master)
{
	master->params = malloc(sizeof(t_params));
	memset(master->params, 0, sizeof(t_params));
}

int	main(int argc, char **argv)
{
	t_master	*master;

	master = malloc(sizeof(t_master));
	memset(master, 0, sizeof(t_master));
	init_master(master);
	if (ft_parsing(argc, argv, master->params))
	{
		printf("%d\n", master->params->n_philo);
		printf("%ld\n", master->params->delta_death);
		printf("%ld\n", master->params->delta_eat);
		printf("%ld\n", master->params->delta_sleep);
	}
	free (master);
}