/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:05:00 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/08 22:02:10 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *threading_start(void   *args)
{
    
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
        index++;
    }
    return (0);
}
