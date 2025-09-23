/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_din_ph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:58:11 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/23 14:50:46 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// we transfer t_fork *fork as an argument to avoid using global variables

void	philo_eats(t_philo *philo)
{
	pthread_mutex_lock(&philo->table->table_lock);
	philo->last_meal_eaten = ft_time_in_ms();
	philo->eat_count++;
	pthread_mutex_unlock(&philo->table->table_lock);
	philo_delay(philo->table, philo->table->time_to_eat);
}

void	*philosopher_fn(void *arg)
{
	t_philo	*philo;
	t_fork	*forks;
	t_fork	*left_fork;
	t_fork	*right_fork;

	philo = (t_philo *)arg;
	forks = philo->table->forks;
	left_fork = philo_get_left_fork(philo, forks);
	right_fork = philo_get_right_fork(philo, forks);
	while (1 && !philo->table->simulation_should_end)
	{
		print_status(philo, "is thinking");
		if (philo_take_forks(philo))
		{
			print_status(philo, "is eating");
			philo_eats(philo);
			philosopher_release_both_forks(left_fork, right_fork);
			print_status(philo, "is sleeping");
			philo_delay(philo->table, philo->table->time_to_sleep);
		}
		philo_delay(philo->table, 1);
	}
	return (NULL);
}
