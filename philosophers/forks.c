/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   forks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/23 14:45:03 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/23 14:50:53 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

t_fork	*philo_get_right_fork(t_philo *philo, t_fork *fork)
{
	int	philo_id;

	philo_id = philo->philo_id;
	if (philo_id == philo->table->num_of_philo)
		return (&fork[0]);
	return (&fork[philo_id]);
}

t_fork	*philo_get_left_fork(t_philo *philo, t_fork *fork)
{
	return (&fork[philo->philo_id - 1]);
}

// Reset fork state BEFORE unlocking
void	philosopher_release_both_forks(t_fork *left_fork,
		t_fork *right_fork)
{
	left_fork->philo = NULL;
	left_fork->is_used = 0;
	pthread_mutex_unlock(&left_fork->mutex);
	right_fork->philo = NULL;
	right_fork->is_used = 0;
	pthread_mutex_unlock(&right_fork->mutex);
}
/*
fork is an array of forks.
each philosopher has access to the whole array of forks,
using functions above to get left and right fork
return 1 if fork sucesfully taken

*/

int	philo_take_forks(t_philo *philo)
{
	if (philo->philo_id % 2 == 0)
	{
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->left_fork->mutex);
		print_status(philo, "has taken a fork");
		pthread_mutex_lock(&philo->right_fork->mutex);
		print_status(philo, "has taken a fork");
	}
	return (1);
}
