/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:39:43 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/20 17:07:52 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"



void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->table->table_lock); // Use table-level mutex
	if (!philo->table->simulation_should_end)
		printf("%llu %d %s\n", ft_time_in_ms() - philo->table->start_time, philo->philo_id, status);
	pthread_mutex_unlock(&philo->table->table_lock);
}

/* TBD: later we would get all of it from input, we would need to change a function input parameters
	int num_of_philo;
	unsigned long time_to_die;
	unsigned long time_to_eat;
	unsigned long time_to_sleep;
	int num_must_eat;
*/


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

long long ft_time_in_ms(void)
{
	struct timeval t;
	long long miliseconds;

	gettimeofday(&t, NULL);
	miliseconds = t.tv_sec * 1000LL + t.tv_usec / 1000;
	return (miliseconds);
}