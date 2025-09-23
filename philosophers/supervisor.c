/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:58:56 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/23 14:48:56 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	*supervisor_fn(void *arg)
{
	t_table	*table;
	int		i;

	table = (t_table *)arg;
	(void)table;
	i = 0;
	while (1)
	{
		i = 0;
		while (i < table->num_of_philo)
		{
			if (check_starvation(table, i))
				return (NULL);
			i++;
		}
		if (check_all_full(table))
			return (NULL);
		usleep(10);
	}
	return (NULL);
}

int	check_starvation(t_table *table, int i)
{
	pthread_mutex_lock(&table->table_lock);
	if (table->time_to_die <= ft_time_in_ms() - table->philo[i].last_meal_eaten)
	{
		table->simulation_should_end = 1;
		printf("%llu %d died \n", ft_time_in_ms() - table->start_time,
			table->philo[i].philo_id);
		pthread_mutex_unlock(&table->table_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->table_lock);
	return (0);
}

int	check_all_full(t_table *table)
{
	int	i;

	i = 0;
	if (table->num_must_eat <= 0)
		return (0);
	while (i < table->num_of_philo)
	{
		if (!check_each_full(table, i))
			return (0);
		i++;
	}
	table->simulation_should_end = 1;
	return (1);
}

int	check_each_full(t_table *table, int i)
{
	pthread_mutex_lock(&table->table_lock);
	if (table->num_must_eat <= table->philo[i].eat_count)
	{
		pthread_mutex_unlock(&table->table_lock);
		return (1);
	}
	pthread_mutex_unlock(&table->table_lock);
	return (0);
}
