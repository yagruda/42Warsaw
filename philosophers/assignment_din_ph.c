/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_din_ph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:58:11 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/18 19:40:06 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// we transfer spoon_t *spoon as an argument to avoid using global variables

spoon_t *phil_get_right_spoon(phil_t *phil, spoon_t *spoon)
{
	int phil_id = phil->phil_id;
	
	if (phil_id == 0)
		return &spoon[N_PHILOSOPHER - 1]; // edge case for phil 0: if phil_t->phil_id is 0, right is last spoon_t->spoon_id
	return &spoon[phil_id - 1];
	
}

spoon_t *phil_get_left_spoon(phil_t *phil, spoon_t *spoon)
{
	return &spoon[phil->phil_id];
}
// TBD: as 42 requires, time_to_sleep after eating is set by input. do usleep(time_to_sleep * 1000);
// spoon is an array of spoons. each philosopher has access to the whole array of spoons, using functions above to get left and right spoon
int phil_eat (phil_t *phil, spoon_t *spoon)
{
	spoon_t *left_spoon = phil_get_left_spoon(phil, spoon);
	spoon_t *right_spoon = phil_get_right_spoon(phil, spoon);
	// check if both spoons are available
	// take both spoons (set is_used = 1, set phil pointer to current phil)

	pthread_mutex_lock(&left_spoon->mutex);
	pthread_mutex_lock(&right_spoon->mutex);

	if (left_spoon->is_used == 0 && right_spoon->is_used == 0)
	{
			// both spoons are available
		left_spoon->phil = phil;
		right_spoon->phil = phil;

		//TO BE CHECKED
		left_spoon->is_used = 1;
		right_spoon->is_used = 1;
		
		//The C assert library assert() macro is used in error handling to check if any assumptions made in the program during runtime is correct or not. It is used to catch logical error in the program in the development stage itself.
		assert(left_spoon->phil == phil); // for debug. TBD: remove later
		assert(right_spoon->phil == phil); // for debug. TBD: remove later
		assert(left_spoon->is_used == 1);
		assert(right_spoon->is_used == 1);
		phil->eat_count++;
		
		printf("phil_eat func printf: Philosopher %d is eating with spoons %d and %d his %d time\n", phil->phil_id, left_spoon->spoon_id, right_spoon->spoon_id, phil->eat_count);
	}
	else
	{
		pthread_mutex_unlock(&left_spoon->mutex);
		pthread_mutex_unlock(&right_spoon->mutex);
		return 0; // spoons not available
	}

	return 1; // spoons successfully taken

	sleep(1);
	
}

void philosopher_release_both_spoons(phil_t *phil, spoon_t *left_spoon, spoon_t *right_spoon)
{
	
	assert(left_spoon->phil == phil); // for debug. TBD: remove later
	assert(left_spoon->is_used == 1);

	assert(right_spoon->phil == phil); // for debug. TBD: remove later
	assert(right_spoon->is_used == 1);
	
	left_spoon->phil = NULL;
	left_spoon->is_used = 0;
	right_spoon->phil = NULL;
	right_spoon->is_used = 0;

	pthread_mutex_unlock(&left_spoon->mutex);
	pthread_mutex_unlock(&right_spoon->mutex);
	
	printf("philosopher_release_both_spoons func printf: Philosopher %d released spoons %d and %d\n", phil->phil_id, left_spoon->spoon_id, right_spoon->spoon_id);
}

int philosopher_get_access_both_spoons(phil_t *phil, spoon_t *spoon)
{
	phil_get_left_spoon(phil, spoon);
	phil_get_right_spoon(phil, spoon);
	
	return (1);
}

// is a thread function for each philo

void* philosopher_fn(void* arg)
{
	(void)arg;
	printf("thread created\n");

	while(1)
	{
		write(1, "rolling\n", 8);
		fflush(stdout);
	}

	return NULL;
}

void* philosopher_fn_old(void *arg)
{
	thread_args_t *thread_args = (thread_args_t*) arg;
	phil_t *phil = thread_args->phil;
	spoon_t *spoon = thread_args->spoon;

	spoon_t *left_spoon = phil_get_left_spoon(phil, spoon);
	spoon_t *right_spoon = phil_get_right_spoon(phil, spoon);

	
	while(1)
	{
		printf("hey\n");
		if (philosopher_get_access_both_spoons(phil, spoon))
		{
			phil_eat(phil, spoon);
			philosopher_release_both_spoons(phil, left_spoon, right_spoon);
			printf("philosopher_fn func printf: Philosopher %d is thinking\n", phil->phil_id);
			sleep(1); // simulate thinking
		}
		
	}
	
	return NULL;
}
