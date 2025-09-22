/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_din_ph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:58:11 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/22 16:47:55 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// we transfer t_fork *fork as an argument to avoid using global variables

t_fork *philo_get_right_fork(t_philo *philo, t_fork *fork)
{
    int philo_id = philo->philo_id;

    // edge case or last philo
    if (philo_id == philo->table->num_of_philo)
        return &fork[0];
    return &fork[philo_id];
}

t_fork *philo_get_left_fork(t_philo *philo, t_fork *fork)
{
    return &fork[philo->philo_id - 1];
}

// fork is an array of forks. each philosopher has access to the whole array of forks, using functions above to get left and right fork

int philo_take_forks(t_philo *philo)
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

    return 1; // forks successfully taken

}


// unsigned longs and while to break if simulation_should_end
// TBD: answer a question to yourself: do I need to make philo_delay ? or just use sleep() in philosopher_fn? usleep isn't precise enough for 42. 
void philo_eats (t_philo *philo)
{

    pthread_mutex_lock(&philo->table->table_lock);
    philo->last_meal_eaten = ft_time_in_ms();
    philo->eat_count++;
    pthread_mutex_unlock(&philo->table->table_lock);
    philo_delay(philo->table, philo->table->time_to_eat);
}


void philosopher_release_both_forks(t_philo *philo, t_fork *left_fork, t_fork *right_fork)
{
    (void)philo;

    // Reset fork state BEFORE unlocking
    left_fork->philo = NULL;
    left_fork->is_used = 0;
    pthread_mutex_unlock(&left_fork->mutex);
    
    right_fork->philo = NULL;
    right_fork->is_used = 0;
    pthread_mutex_unlock(&right_fork->mutex);
}

void* philosopher_fn(void *arg)
{
    t_philo *philo = (t_philo*) arg;
    t_fork *forks = philo->table->forks;

    t_fork *left_fork = philo_get_left_fork(philo, forks);
    t_fork *right_fork = philo_get_right_fork(philo, forks);

    while(1 && !philo->table->simulation_should_end)
    {
        print_status(philo, "is thinking");
        if(philo_take_forks(philo))
        {
            print_status(philo, "is eating");
            philo_eats(philo);
            philosopher_release_both_forks(philo, left_fork, right_fork);
            print_status(philo, "is sleeping");
            philo_delay(philo->table, philo->table->time_to_sleep);
        }
        philo_delay(philo->table, 1);
    }

    return NULL;
}
