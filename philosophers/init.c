/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/19 18:35:15 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/22 16:44:28 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int init_all (t_philo** philosophers, t_table** table, t_fork** forks, int input_num_of_philo)
{
	if (structures_malloc(philosophers, forks, table, input_num_of_philo))
		return 1;
	initial_init_table(*table, *philosophers, *forks);
	init_forks_filos(*philosophers,*forks, input_num_of_philo, *table);

	return(0);
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
        philosophers[i].last_meal_eaten = ft_time_in_ms();
        philosophers[i].table = table;
        
        // Set fork pointers once during initialization
        philosophers[i].left_fork = &forks[i];
        philosophers[i].right_fork = &forks[(i + 1) % n_philos];
        
        i++;
    }
}


void initial_init_table(t_table* table, t_philo* philosophers, t_fork* forks)
{
	table->start_time = ft_time_in_ms();
	table->simulation_should_end = 0;
	table->philo = philosophers;
	table->forks = forks;
	pthread_mutex_init(&table->table_lock, NULL);
	
}

void final_init_table(t_table* table, int argc, char** argv)  // Remove t_philo** philosophers parameter
{
    table->num_of_philo = ft_atoi(argv[1]);
    table->time_to_die = ft_atoi(argv[2]);
    table->time_to_eat = ft_atoi(argv[3]);
    table->time_to_sleep = ft_atoi(argv[4]);
    if (argc == 6)
        table->num_must_eat = ft_atoi(argv[5]);
    else 
        table->num_must_eat = -1;
    
    create_philo_threads(table->philo);  // Use table->philo instead of *philosophers
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
			break; 
		}
		i++;
		usleep(60);
	}
}

