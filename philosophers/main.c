/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:01 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/22 15:05:04 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdint.h> // for uint64_t


static void cleanup_resources(t_philo *philosophers, t_fork *forks, t_table *table)
{
	int i;

	i = 0;
	while (i < table->num_of_philo)
	{
		pthread_mutex_destroy(&forks[i].mutex);
		i++;
	}
	
	pthread_mutex_destroy(&table->table_lock);
	free(forks);
	free(philosophers);
	free(table);
}

static void join_all_threads(t_philo *philosophers, pthread_t supervisor, int n_philos)
{
	int i;

	i = 0;

	while (i < n_philos)
	{
		pthread_join(philosophers[i].thread_handle, NULL);
		i++;
	}
	pthread_join(supervisor, NULL);
	
}

int main(int argc, char** argv)
{	
	int input_num_of_philo; // transfer to table, so work without it in main
	t_fork* forks;
	t_philo* philosophers;
	pthread_t supervisor;
	t_table* table;

	input_num_of_philo = input_check(argc, argv);	
	if(input_num_of_philo < 1)
		return 1;
	else if (input_num_of_philo == 1)
	{
		printf("0 1 died \n");
		return 0;
	}

	if (init_all(&philosophers, &table, &forks, input_num_of_philo))
		return 1;
	final_init_table(table, argc, argv, &philosophers);

	pthread_create(&supervisor, NULL, supervisor_fn, table);
	join_all_threads(philosophers, supervisor, input_num_of_philo);

	cleanup_resources(philosophers, forks, table);

	return 0;
}



