/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:55:01 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/16 19:59:51 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"
#include <sys/time.h>
#include <stdio.h>
#include <stdint.h> // for uint64_t


int main(void)
{
	phil_t phil[N_PHILOSOPHER]; // create an array of 5 phil_t philosophers 
	spoon_t spoon[N_PHILOSOPHER]; // create an array of 5 spoon_t spoons
	pthread_attr_t attr; // TBD change later as it's not allowed in 42 
	int i = 0;
	
	// spoon init	
	while (i < N_PHILOSOPHER)
	{
		spoon[i].spoon_id = i;
		spoon[i].is_used = 0;
		spoon[i].phil = NULL;
		pthread_mutex_init(&spoon[i].mutex, NULL);
		pthread_cond_init(&spoon[i].cv, NULL); // TBD: Change to 42 semaphore.  for thread coordionation competing for this resource.
		i++;
	}

	pthread_attr_init(&attr); // TBD change later as it's not allowed in 42
	pthread_attr_setdetachstate(&attr, PTHREAD_CREATE_DETACHED); // TBD change later as it's not allowed in 42
	// Detached thread = cleans up its own resources automatically when it finishes. You cannot pthread_join it.
	// Joinable thread (default) = you must pthread_join it, otherwise you leak. That's the reason why use pthread_detach().

	i = 0;
	
	// create philosophers threads
	while(i < N_PHILOSOPHER)
	{
		phil[i].phil_id = i;
		phil[i].eat_count = 0;
		pthread_create(&phil[i].thread_handle, &attr, philosopher_fn, &phil[i]);
		i++;
	}

	phil_eat(&phil[0], spoon); // test call

	return 0;
}

