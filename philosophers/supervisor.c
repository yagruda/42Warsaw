/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   supervisor.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 15:58:56 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/20 17:33:26 by yhruda           ###   ########.fr       */
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
// old code; if (table->time_to_die <= table->philo[i].last_meal_eaten) not correct. 