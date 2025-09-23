/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/10 13:54:07 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/23 14:50:35 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

// include Libft inside
# include "Includes/ft_printf.h"
# include <pthread.h>
# include <stdint.h>
# include <stdio.h>
# include <sys/time.h>
// stdint for uint64_t

typedef struct s_philo
{
	pthread_t			thread_handle;
	int					philo_id;
	int					eat_count;
	unsigned long		last_meal_eaten;
	struct s_table		*table;

	struct s_fork		*left_fork;
	struct s_fork		*right_fork;

}						t_philo;

typedef struct s_fork
{
	int					fork_id;
	int					is_used;
	t_philo				*philo;
	pthread_mutex_t		mutex;
}						t_fork;

typedef struct s_table
{
	int					num_of_philo;
	unsigned long		time_to_die;
	unsigned long		time_to_eat;
	unsigned long		time_to_sleep;
	int					num_must_eat;

	unsigned long long	start_time;
	int					simulation_should_end;

	t_philo				*philo;
	t_fork				*forks;

	pthread_mutex_t		table_lock;

}						t_table;

t_fork					*philo_get_right_fork(t_philo *philo, t_fork *fork);
t_fork					*philo_get_left_fork(t_philo *philo, t_fork *fork);
int						philo_take_forks(t_philo *philo);
void					philosopher_release_both_forks(t_fork *left_fork,
							t_fork *right_fork);
int						philosopher_get_access_both_forks(t_philo *philo,
							t_fork *fork);
void					*philosopher_fn(void *arg);

void					*supervisor_fn(void *arg);
int						check_starvation(t_table *table, int i);
int						check_each_full(t_table *table, int i);
int						check_all_full(t_table *table);

void					print_status(t_philo *philo, const char *status);
void					init_forks_filos(t_philo *philosophers, t_fork *forks,
							int n_philos, t_table *table);
void					create_philo_threads(t_philo *philosophers);
void					initial_init_table(t_table *table,
							t_philo *philosophers, t_fork *forks);
long long				ft_time_in_ms(void);
void					philo_delay(t_table *table,
							unsigned long delay_duration_ms);

int						input_check(int argc, char **argv);
int						structures_malloc(t_philo **philo, t_fork **fork,
							t_table **table, int n_philos);
int						init_all(t_philo **philosophers, t_table **table,
							t_fork **forks, int input_num_of_philo);
void					final_init_table(t_table *table, int argc, char **argv);

#endif
