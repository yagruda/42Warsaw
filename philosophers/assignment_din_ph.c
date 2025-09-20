/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assignment_din_ph.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhruda <yhruda@student.42warsaw.pl>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/16 12:58:11 by yhruda            #+#    #+#             */
/*   Updated: 2025/09/20 17:33:28 by yhruda           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// we transfer t_fork *fork as an argument to avoid using global variables

t_fork *philo_get_right_fork(t_philo *philo, t_fork *fork)
{
    int philo_id = philo->philo_id;

    // if 0 element 
    if (philo_id == 1)
        return &fork[philo->table->num_of_philo - 1]; // edge case for philo 1: right is last fork
    return &fork[philo_id - 2];
}

t_fork *philo_get_left_fork(t_philo *philo, t_fork *fork)
{
    return &fork[philo->philo_id - 1];
}

// fork is an array of forks. each philosopher has access to the whole array of forks, using functions above to get left and right fork

int philo_take_forks (t_philo *philo, t_fork *fork)
{
    t_fork *left_fork = philo_get_left_fork(philo, fork);
    t_fork *right_fork = philo_get_right_fork(philo, fork);

    if (philo->philo_id % 2 == 0)
    {
        pthread_mutex_lock(&right_fork->mutex);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&left_fork->mutex);
        print_status(philo, "has taken a fork");
    }
    else
    {
        pthread_mutex_lock(&left_fork->mutex);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&right_fork->mutex);
        print_status(philo, "has taken a fork");
    }

    return 1; // forks successfully taken

    
}


// TBD: answer a question to yourself: do I need to make philo_delay ? or just use sleep() in philosopher_fn? usleep isn't precise enough for 42. 
void philo_eats (t_philo *philo)
{
    pthread_mutex_lock(&philo->table->table_lock);
    philo->last_meal_eaten = ft_time_in_ms();
    philo->eat_count++;
    pthread_mutex_unlock(&philo->table->table_lock);
    usleep(philo->table->time_to_eat * 1000);
}


void philosopher_release_both_forks(t_philo *philo, t_fork *left_fork, t_fork *right_fork)
{
    // assert(left_fork->philo == philo); // for debug. TBD: remove later
    // assert(left_fork->is_used == 1);

    // assert(right_fork->philo == philo); // for debug. TBD: remove later
    // assert(right_fork->is_used == 1);

    (void)philo;

    left_fork->philo = NULL;
    left_fork->is_used = 0;
    right_fork->philo = NULL;
    right_fork->is_used = 0;
    
    pthread_mutex_unlock(&left_fork->mutex);
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
        if(philo_take_forks(philo, forks))
        {
            print_status(philo, "is eating");
            philo_eats(philo);
            philosopher_release_both_forks(philo, left_fork, right_fork);
            print_status(philo, "is sleeping");
            usleep(philo->table->time_to_sleep * 1000);
            
            // TBD: usleep(philo->table->time_to_sleep * 1000);
        }
        
        usleep(10);
    }

    return NULL;
}
