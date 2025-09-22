/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:58:56 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/22 16:20:07 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void* supervisor_fn(void *arg)
{
	t_table* table = (t_table*) arg;
	(void)table;
	int i;

	i = 0;
	
	while(1)
	{
		i = 0;
		while (i < table->num_of_philo)
		{
			if (check_starvation(table, i))
				return NULL;
			i++;
		}
		if (check_all_full(table))
			return NULL;
		usleep(10);
	}
	return NULL;
}

// check if any philosopher died (if current time - last meal time => time to die -> kill all threads and write who died)
// go into each philo through table and check if time since last meal is > than time to die
int check_starvation(t_table* table, int i)
{
	pthread_mutex_lock(&table->table_lock);
	// TBD before run: check do i even update last_meal_eaten?
	if (table->time_to_die <= ft_time_in_ms() - table->philo[i].last_meal_eaten)
	{
		table->simulation_should_end = 1;
		//printf("PHILO %d IS STARVING MAFAKAAAA, time since last food: %lld\n", table->philo[i].philo_id, ft_time_in_ms() - table->philo[i].last_meal_eaten);
		printf("%llu %d died \n", ft_time_in_ms() - table->start_time, table->philo[i].philo_id);
		pthread_mutex_unlock(&table->table_lock);
		return(1);
	}
	pthread_mutex_unlock(&table->table_lock);
	return 0;
	
}

int check_all_full(t_table* table)
{
	int i;
	
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
	// printf("ALL PHILOS ARE FULL\n");
	
	return (1);
}

int check_each_full(t_table* table, int i)
{
	// maybe add mutex lock here too, to be sure

	pthread_mutex_lock(&table->table_lock);
	
	if (table->num_must_eat <= table->philo[i].eat_count)
	{
		pthread_mutex_unlock(&table->table_lock);
	//	printf("ONE PHILO IS FULL\n");
		return (1);
	}
	pthread_mutex_unlock(&table->table_lock);
	
	return 0;
	
}
