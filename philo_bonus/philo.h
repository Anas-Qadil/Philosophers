/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:28:16 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/13 23:58:49 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS
#define PHILO_BONUS

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/time.h>
#include <signal.h>

typedef	struct			s_philo
{
	int					philo_id;
	int					philo_ate;
	int					philo_done_eating;
	int					left_fork;
	int					right_fork;
	long long int		last_philo_meal;
	pid_t		        process_id;
    pthread_t           philo_thread;
	struct s_data		*philo_data;
}						t_philo;

typedef struct			s_data
{
	int					number_of_philo;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					number_of_eat;
	int					philo_died;
	int					all_ate;
	long long int		time_stamp;
	sem_t		        *meal;
	sem_t		        *forks;
	sem_t               *message;
    t_philo             philo[200];
}						t_data;


int init_data(t_data *philo_data, char **argv);
int	ft_atoi(const char *str);
long long int	get_time(void);
long long int	time_diff(long long int old, long long int new);

void	put_error(int code);

int    start_philo(t_data *philo_data);
void    start_process(t_philo *philo);
void    *night_watch(void *arg_philo);

void	put_message(t_data *philo_data, int id, char *message);
void	time_to_sleep(int time, t_data *philo_data);


void    close_things(t_data *philo_data);

#endif