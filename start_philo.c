/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:05:00 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/09 21:34:15 by aqadil           ###   ########.fr       */
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
    time_to_sleep(philo_data->time_to_eat, philo_data);
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
    if (philo->philo_id)
        usleep(15000);
    while (!(philo_data->philo_died))
    {
        start_eating(philo);
        if (philo_data->all_ate)
            break;
        put_message(philo_data, philo->philo_id, "is sleeping");
        time_to_sleep(philo_data->time_to_sleep, philo_data);
        put_message(philo_data, philo->philo_id, "Is Thinking");
        index++;
    }
    return (NULL);
}

void    check_philo_death(t_data *philo_data, t_philo *philo)
{
    int index;

    index = -1;
    while (!(philo_data->all_ate))
    {
        index = -1;
        while (++index < philo_data->number_of_philo && !(philo_data->philo_died))
        {
            if (time_diff(philo[index].last_meal, philo_time() > philo_data->time_to_die))
            {
                put_message(philo_data, index, "Died");
                philo_data->philo_died = 1;
            }
            usleep(100);
        }
        if (philo_data->philo_died)
            break;
    }
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
        if (pthread_create(&(philo[index].philo), NULL, threading_start, &(philo[index])))
            return (1);
        philo[index].last_meal = philo_time();
        index++;
    }
    check_philo_death(philo_data, philo_data->philo);
    join_and_destroy(philo_data, philo);
    return (0);
}

void    join_and_destroy(t_data *philo_data, t_philo *philo)
{
    int index;

    index = -1;
    while (++index < philo_data->number_of_philo)
        pthread_join(philo[index].philo, NULL);
    index = -1;
    while (++index < philo_data->number_of_philo)
        pthread_mutex_destroy(&(philo_data->fork[index]));
    pthread_mutex_destroy(&(philo_data->message));
}