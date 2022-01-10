/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 17:30:50 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/10 01:52:15 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <sys/time.h>
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <pthread.h>


typedef	struct			s_philo
{
	int					philo_id;
	int					philo_ate;
	int					left_fork;
	int					right_fork;
	long long			last_philo_meal;
	pthread_t			philo;
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
	long long			time_stamp;
	pthread_mutex_t		meal;
	pthread_mutex_t		forks[200];
	pthread_mutex_t		message;
	t_philo		philo[200];
}						t_data;


int		write_error(char *str);
int		error_manager(int error);
int		init_data(t_data *philo_data, char **argv);
int			ft_atoi(const char *str);
void		put_message(t_data *philo_data, int id, char *string);
long long	timestamp(void);
long long	time_diff(long long past, long long pres);
void		time_to_sleep(long long time, t_data *philo_data);
int			start_philo(t_data *philo_data);
void		join_and_destroy(t_data *philo_data, t_philo *philos);
int	init_mutex(t_data *philo_data);
int	init_philo(t_data *philo_data);

#endif