/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:34:15 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/13 16:15:34 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

void    start_eating(t_philo *philo)
{
    
}

void    start_process(t_philo *philo)
{
    t_data  *philo_data;

    philo_data = philo->philo_data;
    philo->last_philo_meal = get_time();
    pthread_create(&(philo->philo_thread), NULL, night_watch, philo);
    if (philo->philo_id % 2)
        usleep(1000);
    while (!(philo_data->philo_died))
    {
        start_eating(philo);
        if (philo_data->number_of_eat != -1 && philo->philo_ate >= philo_data->number_of_philo)
            break;
        put_message(philo_data, philo->philo_id, "is sleeping");
        time_to_sleep(philo_data->time_to_sleep, philo_data);
        put_message(philo_data, philo->philo_id, "is thinking");
    }
    pthread_join(philo->philo_thread, NULL);
    if (philo_data->philo_died)
        exit(1);
    exit(0);
}

int    start_philo(t_data *philo_data)
{
    int index;
    t_philo *philo;

    index = -1;
    philo = philo_data->philo;
    philo_data->time_stamp = get_time();
    while (++index < philo_data->number_of_philo)
    {
        philo[index].process_id = fork();
        if (philo[index].process_id < 0)
            return (1);
        if (philo[index].process_id == 0)
            start_process(&philo[index]);
        usleep(50);
    }
    return (0);
}

void    *night_watch(void *arg_philo)
{
    
}