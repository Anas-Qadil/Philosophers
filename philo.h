/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:30:50 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/09 21:07:13 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
#define PHILO_H

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/time.h>

struct s_data;

typedef struct s_philo
{
    int philo_id;
    int philo_ate;
    int left_fork;
    int right_fork;
    long long int last_meal;
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
    pthread_mutex_t fork[200];
    pthread_mutex_t message;
    t_philo philo[200];
}   t_data;

// tools functions
int	ft_atoi(const char *str);

// Error functions
void    exit_error(int code);
void    exit_error_v_2(int code);

// init functions
int init_data(t_data   *philo_data, char **argv);
int init_mutex(t_data *philo_data);

// runing those motherfuckers
int start_philo(t_data *philo_data);
long long int	philo_time(void);
long long int time_diff(long long int old, long long int new);

// threading start
void    *threading_start(void   *args);

// messaging 
void	put_message(t_data *philo_data, int	philo_id, char *message);

// timing
void	time_to_sleep(long long int time, t_data *philo_data);

// join and exit
void    join_and_destroy(t_data *philo_data, t_philo *philo);
void    check_philo_death(t_data *philo_data, t_philo *philo);

#endif