/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:54:07 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/20 16:53:26 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

#include "Includes/ft_printf.h" // include Libft inside
#include <pthread.h>
#include <stdio.h>
#include "sys/time.h"

#include <assert.h> // TBD: delete later. for debug only

typedef struct s_philo
{
	// s
	pthread_t thread_handle;
	int philo_id;
	int eat_count; // TBD: for last input make a check -if eat count == required eat count -> finish simulation
	unsigned long last_meal_eaten; // TBD: later use it in supervisor to check if philo died
	struct s_table *table; // pointer to shared table, so we wouldn't need to paste t_table table in every function
	
} t_philo;



typedef struct s_fork
{
	int fork_id; // t_fork position in array + 1
	int is_used;
	t_philo *philo; // if is_used == 1, set pointer to philosopher using the fork. otherwise reset to NULL
	pthread_mutex_t mutex;
} t_fork;

typedef struct s_table
{
	int num_of_philo;
	unsigned long time_to_die;
	unsigned long time_to_eat;
	unsigned long time_to_sleep;
	int num_must_eat;

	unsigned long long start_time;
	int simulation_should_end;

	t_philo *philo;
	t_fork *forks;

	pthread_mutex_t table_lock;

	// maybe add mutex. I guess no need for mutex since only supervisor thread accesses shared data.

} t_table;

// assignment_din_ph.c

t_fork *philo_get_right_fork(t_philo *philo, t_fork *fork);
t_fork *philo_get_left_fork(t_philo *philo, t_fork *fork);
int philo_take_forks (t_philo *philo, t_fork *fork);
void philosopher_release_both_forks(t_philo *philo, t_fork *left_fork, t_fork *right_fork);
int philosopher_get_access_both_forks(t_philo *philo, t_fork *fork);
void* philosopher_fn(void *arg);

// supervisor.c
void* supervisor_fn(void *arg);
int check_starvation(t_table* table, int i);

// main.c


//helpers.c

void	print_status(t_philo *philo, const char *status);
void init_forks_filos(t_philo *philosophers, t_fork *forks, int n_philos, t_table* table);
void create_philo_threads(t_philo* philosophers);
void init_table(t_table* table, t_philo* philosophers, t_fork* forks, int n_philos);
long long ft_time_in_ms(void);
void	philo_delay(t_table *table, unsigned long delay_duration_ms);

//init.c
int input_check(int argc, char** argv);
int structures_malloc(t_philo** philo, t_fork** fork, t_table** table, int n_philos);
int init_all (t_philo** philosophers, t_table** table, t_fork** forks, int input_num_of_philo);

#endif
