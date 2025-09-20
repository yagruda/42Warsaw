/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 12:39:43 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/19 22:22:37 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_status(t_philo *philo, char *status)
{
	pthread_mutex_lock(&philo->print_lock);
	if (!philo->table->simulation_should_end)
		printf("%d is %s\n", philo->philo_id, status);
	pthread_mutex_unlock(&philo->print_lock);
}

// spoon and philosophers init	
// i do spoon_id + 1 and phil_id + 1 to start from 1. Accordingly, imagine as -1 position in array.
void init_forks_filos(t_philo *philosophers, t_fork *forks, int n_philos, t_table* table) 
{
	int i;
	i = 0;
	while (i < n_philos)
	{
		forks[i].fork_id = i + 1;
		forks[i].is_used = 0;
		forks[i].philo = NULL;
		pthread_mutex_init(&forks[i].mutex, NULL);
		philosophers[i].philo_id = i + 1;
		philosophers[i].eat_count = 0;
		philosophers[i].last_meal_eaten = 0;
		philosophers[i].table = table;
		pthread_mutex_init(&philosophers[i].print_lock, NULL);
		i++;
	}
}

/* TBD: later we would get all of it from input, we would need to change a function input parameters
	int num_of_philo;
	unsigned long time_to_die;
	unsigned long time_to_eat;
	unsigned long time_to_sleep;
	int num_must_eat;
*/
void init_table(t_table* table, t_philo* philosophers, t_fork* forks, int n_philos)
{
	table->num_of_philo = n_philos;
	table->time_to_die = 800;
	table->time_to_eat = 200;
	table->time_to_sleep = 200;
	table->num_must_eat = -1; // -1 means no limit
	table->start_time = ft_time_in_ms();
	table->simulation_should_end = 0;
	table->philo = philosophers;
	table->forks = forks;
}

// create philosophers thread
// Detached thread = cleans up its own resources automatically when it finishes. You cannot pthread_join it.
// Joinable thread (default) = you must pthread_join it, otherwise you leak. That's the reason why use pthread_detach().	
void create_philo_threads(t_philo* philosophers)
{
	int i;

	i = 0;
	while(i < philosophers->table->num_of_philo)
	{
		// below do I need tow rite philosopher_fn with & or without ? 
		if (pthread_create(&philosophers[i].thread_handle, NULL, philosopher_fn, &philosophers[i]) != 0)
		{
			printf("Failed to create thread");
			return; 
		}
		i++;
		usleep(60);
	}
}

long long ft_time_in_ms(void)
{
	struct timeval t;
	long long miliseconds;

	gettimeofday(&t, NULL);
	miliseconds = t.tv_sec * 1000LL + t.tv_usec / 1000;
	return (miliseconds);
}