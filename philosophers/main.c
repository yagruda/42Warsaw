/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:01 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/18 19:42:24 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdint.h> // for uint64_t


int main(void)
{
	thread_args_t thread_args[N_PHILOSOPHER];
	spoon_t spoons[N_PHILOSOPHER];
	phil_t philosophers[N_PHILOSOPHER];
	
	pthread_attr_t attr; // TBD change later as it's not allowed in 42 
	int i = 0;
	
	// spoon init	
	while (i < N_PHILOSOPHER)
	{
		spoons[i].spoon_id = i;
		spoons[i].is_used = 0;
		spoons[i].phil = NULL;
		pthread_mutex_init(&spoons[i].mutex, NULL);
		pthread_cond_init(&spoons[i].cv, NULL); // TBD: Change as 42 wouldn't allow it
		i++;
	}

	pthread_attr_init(&attr); // TBD change later as it's not allowed in 42
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // TBD change later as it's not allowed in 42
	// Detached thread = cleans up its own resources automatically when it finishes. You cannot pthread_join it.
	// Joinable thread (default) = you must pthread_join it, otherwise you leak. That's the reason why use pthread_detach().

	i = 0;
	
	// create philosophers threads
	// &philosophers[i], &spoons[i] copy addres, not a value!
	while(i < N_PHILOSOPHER)
	{
		philosophers[i].phil_id = i;
		philosophers[i].eat_count = 0;
		thread_args[i].phil = &philosophers[i]; 
		thread_args[i].spoon = &spoons[i];
		printf("spoon[i] id from a structure is %d, it's assigned sucessfully \n", thread_args[i].spoon->spoon_id);
		pthread_create(&thread_args[i].phil->thread_handle, &attr, philosopher_fn, &thread_args[i]); 
		i++;

		
		usleep(60);
	}

	// phil_eat(&philosophers[0], spoons); // test call

	return 0;
}

