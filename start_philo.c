/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:05:00 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/08 22:40:38 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    start_eating(t_philo *philo)
{
    t_data  *philo_data;

    philo_data = philo->philo_data;
    pthread_mutex_lock(&(philo_data->fork[philo->left_fork]));
    put_message(philo_data, philo->philo_id, "Has Taken A Fork");
    pthread_mutex_lock(&(philo_data->fork[philo->right_fork]));
    put_message(philo_data, philo->philo_id, "Has Taken A Fork");
    pthread_mutex_lock(&(philo_data->meal));
    put_message(philo_data, philo->philo_id, "is eating");
    philo->last_meal = philo_time();
    pthread_mutex_unlock(&(philo_data->meal));
    // time_to_sleep();
    (philo->philo_ate)++;
    pthread_mutex_unlock(&(philo_data->fork[philo->left_fork]));
    pthread_mutex_unlock(&(philo_data->fork[philo->right_fork]));
}

void    *threading_start(void   *args_philo)
{
    t_philo *philo;
    t_data  *philo_data;
    int index;

    index = 0;
    philo = (t_philo *)args_philo;
    philo_data = philo->philo_data;
    if (philo->philo_id % 2)
        usleep(15000);
    while (!(philo_data->philo_died))
    {
        start_eating(philo);
        if (philo_data->all_ate)
            break;
        put_message(philo_data, philo->philo_id, "is sleeping");
    }
    return (NULL);
}

int start_philo(t_data *philo_data)
{
    int index;
    t_philo *philo;

    index = 0;
    philo = philo_data->philo;
    philo_data->time_stamp = philo_time();
    while (index < philo_data->number_of_philo)
    {
        if (pthread_create(&(philo[index].philo), NULL, &threading_start, (void *)philo))
            return (1);
        philo[index].last_meal = philo_time();
        index++;
    }
    return (0);
}
