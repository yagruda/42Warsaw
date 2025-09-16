/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_din_ph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:58:11 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/16 20:00:30 by yhruda           ###   ########.fr       */
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
void phil_eat (phil_t *phil, spoon_t *spoon)
{
	spoon_t *left_spoon = phil_get_left_spoon(phil, spoon);
	spoon_t *right_spoon = phil_get_right_spoon(phil, spoon);
	// check if both spoons are available
	// take both spoons (set is_used = 1, set phil pointer to current phil)

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
	sleep(1);
	
}

void philosopher_release_both_spoons(phil_t *phil, spoon_t *left_spoon, spoon_t *right_spoon)
{
	left_spoon->phil = NULL;
	left_spoon->is_used = 0;
	right_spoon->phil = NULL;
	right_spoon->is_used = 0;
	printf("philosopher_release_both_spoons func printf: Philosopher %d released spoons %d and %d\n", phil->phil_id, left_spoon->spoon_id, right_spoon->spoon_id);
}

int philosopher_get_access_both_spoons(phil_t *phil, spoon_t *spoon)
{
	phil_get_left_spoon(phil, spoon);
	phil_get_right_spoon(phil, spoon);
	
	return (1);
}
void* philosopher_fn(void *arg)
{
	(void)arg;
	// generic code for all philosophers
	return NULL;
}
