/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:54:07 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/16 19:59:01 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include "Includes/ft_printf.h" // include Libft inside
#include <pthread.h>
#include <stdio.h>

#define N_PHILOSOPHER 5 // TBD: later change to input value;
#include <assert.h> // TBD: delete later. for debug only



typedef struct phil_s
{
	int phil_id;
	pthread_t thread_handle;
	int eat_count; // TBD: for last input make a check -if eat count == required eat count -> finish simulation
} phil_t;

typedef struct spoon_s
{
	int spoon_id; // ME: phil can take phil_id + 1 and phil_id - 1 spoons;
	int is_used; // 0 is free, 1 is used
	phil_t *phil; // if is_used == 1, set pointer to philosopher using the spoon. otherwise reset to NULL
	pthread_mutex_t mutex; // for mutual exclusion
	pthread_cond_t cv; //TBD: Change to 42 semaphore.  for thread coordionation competing for this resource. 
} spoon_t;


// assignment_din_ph.c
spoon_t *phil_get_right_spoon(phil_t *phil, spoon_t *spoon);
spoon_t *phil_get_left_spoon(phil_t *phil, spoon_t *spoon);
void phil_eat (phil_t *phil, spoon_t *spoon);
void philosopher_release_both_spoons(phil_t *phil, spoon_t *left_spoon, spoon_t *right_spoon);
int philosopher_get_access_both_spoons(phil_t *phil, spoon_t *spoon);

// main.c
void* philosopher_fn(void *arg);



#endif
