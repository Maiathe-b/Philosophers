/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jomaia <jomaia@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/03 13:15:35 by jomaia            #+#    #+#             */
/*   Updated: 2026/03/05 18:01:54 by jomaia           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	ft_check_valid(char *arg)
{
	int	number;

	number = ft_atoi(arg);
	if (number < 0 || number / __LONG_MAX__> 1)
		return (false);
	return (true);
}

static void	assign(char **argv, t_params *params)
{
	params->n_philo = ft_atoi(argv[1]);
	params->delta_death = ft_atoi(argv[2]);
	params->delta_eat = ft_atoi(argv[3]);
	params->delta_sleep = ft_atoi(argv[4]);
	if (argv[5])
		params->_n_meals = ft_atoi(argv[5]);
}

bool	ft_parsing(int argc, char **argv, t_params *params)
{
	params = malloc (sizeof(t_params));
	memset(params, 0, sizeof(t_params));
	if (argc < 5 || argc > 6)
		return (0);
	if (!ft_check_valid(argv[1]))
		return (printf("Invalid number of philosophers\n"), 0);
	if (!ft_check_valid(argv[2]))
		return (printf("Invalid time to die\n"), 0);
	if (!ft_check_valid(argv[3]))
		return (printf("Invalid time to eat\n"), 0);
	if (!ft_check_valid(argv[4]))
		return (printf("Invalid time to sleep\n"), 0);
	if (argv[5])
		if (!ft_check_valid(argv[5]))
			return (printf("Invalid number of repetitions\n"), 0);
	assign(argv, params);
	return (1);
}