/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:35:15 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/19 22:23:00 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// TBD, it's basic version
int input_check(int argc, char** argv)
{
	if (argc < 2)
	{
		printf("Error: wrong number of arguments. Please provide number of philosophers.\n");
		return -1;
	}

	// TBD: what's about wrong input - not a number?
	return (ft_atoi(argv[1]));
}
int structures_malloc(t_philo** philo, t_fork** fork, t_table** table, int n_philos)
{
	// as philo, fork, table are passed as a pointer to a pointer, but in a fact they are arrays of structures, we need to use * to derefence them
	*philo = malloc(sizeof(t_philo) * n_philos);
	*fork = malloc(sizeof(t_fork) * n_philos);
	*table = malloc(sizeof(t_table));
	if (!philo || !fork || !table)
	{
		printf("Error: malloc failed\n");
		return 1;
	}

	return 0;
}