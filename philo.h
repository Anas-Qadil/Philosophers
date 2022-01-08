/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:30:50 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/08 17:59:09 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

struct s_data;

typedef struct s_philo
{
    int philo_id;
    int philo_ate;
    int left_fork;
    int right_fork;
    int last_meal;
    pthread_t   philo;
    struct s_data  *philo_data;
}   t_philo;

typedef struct s_data
{
    int number_of_philo;
    int time_to_die;
    int time_to_eat;
    int time_to_sleep;
    int number_of_eat;
    int philo_died;
    int all_ate;
    long long int time_stamp;
    pthread_mutex_t meal;
    pthread_mutex_t fork[100];
    pthread_mutex_t message;
    t_philo philo[100];
}   t_data;

// tools functions

int	ft_atoi(const char *str);

// Error functions

void    exit_error(int code);

// main functions
int init_data(t_data   *philo_data, char **argv);
int init_mutex(t_data *philo_data);

#endif