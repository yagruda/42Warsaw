/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:01 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/19 22:25:19 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdint.h> // for uint64_t

int main(int argc, char** argv)
{	
	int input_num_of_philo; // transfer to table, so work without it in main
	int i;
	t_fork* forks;
	t_philo* philosophers;
	pthread_t supervisor;
	t_table* table;

	i = 0;
	input_num_of_philo = input_check(argc, argv);	
	if(input_num_of_philo < 2)
		return 1;	
	
	if (structures_malloc(&philosophers, &forks, &table, input_num_of_philo))
		return 1;
	
	init_forks_filos(philosophers,forks, input_num_of_philo, table);
	init_table(table, philosophers, forks, input_num_of_philo);

	create_philo_threads(philosophers);
	pthread_create(&supervisor, NULL, supervisor_fn, table);

	while (i < input_num_of_philo)
	{
		pthread_join(philosophers[i].thread_handle, NULL);
		i++;
	}
	pthread_join(supervisor, NULL);


	(void)forks;
	(void)philosophers;
	(void)table;
	(void)supervisor;
	(void)i;

	printf("finished");

	// dont forget to free what allocated with malloc
	free(forks);
	free(philosophers);

	return 0;
}

