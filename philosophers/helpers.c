/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:39:43 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/23 15:04:43 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, const char *status)
{
	pthread_mutex_lock(&philo->table->table_lock);
	if (!philo->table->simulation_should_end)
		printf("%llu %d %s\n", ft_time_in_ms() - philo->table->start_time,
			philo->philo_id, status);
	pthread_mutex_unlock(&philo->table->table_lock);
}
/*
 as philo, fork, table are passed as a pointer to a pointer,
 but in a fact they are arrays of structures, we need to use
 * to derefence them
*/

int	structures_malloc(t_philo **philo, t_fork **fork, t_table **table,
		int n_philos)
{
	*philo = malloc(sizeof(t_philo) * n_philos);
	*fork = malloc(sizeof(t_fork) * n_philos);
	*table = malloc(sizeof(t_table));
	if (!philo || !fork || !table)
	{
		printf("Error: malloc failed\n");
		return (1);
	}
	return (0);
}

long long	ft_time_in_ms(void)
{
	struct timeval	t;
	long long		miliseconds;

	gettimeofday(&t, NULL);
	miliseconds = t.tv_sec * 1000LL + t.tv_usec / 1000;
	return (miliseconds);
}

void	philo_delay(t_table *table, unsigned long delay_duration_ms)
{
	long long	start_of_delay;

	start_of_delay = ft_time_in_ms();
	while ((ft_time_in_ms() - start_of_delay) < (long long)delay_duration_ms)
	{
		pthread_mutex_lock(&table->table_lock);
		if (table->simulation_should_end)
		{
			pthread_mutex_unlock(&table->table_lock);
			break ;
		}
		pthread_mutex_unlock(&table->table_lock);
		usleep(10);
	}
}
