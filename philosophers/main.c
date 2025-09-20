/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:01 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/20 16:44:39 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdint.h> // for uint64_t


// ad a check case for max number of philos - 250
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
	else if (input_num_of_philo > 200)
	{
		printf("Error: too many philosophers. Max is 200.\n");
		return 1;
	}
	
	if (init_all(&philosophers, &table, &forks, input_num_of_philo))
		return 1;
	
	pthread_create(&supervisor, NULL, supervisor_fn, table);
	while (i < input_num_of_philo)
	{
		pthread_join(philosophers[i].thread_handle, NULL);
		i++;
	}
	pthread_join(supervisor, NULL);
	
	free(forks);
	free(philosophers);
	free(table);

	return 0;
}

