/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 21:05:00 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/14 17:19:50 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	start_eating(t_philo *philo)
{
	t_data	*philo_data;

	philo_data = philo->philo_data;
	pthread_mutex_lock(&(philo_data->forks[philo->left_fork]));
	put_message(philo_data, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(philo_data->forks[philo->right_fork]));
	put_message(philo_data, philo->philo_id, "has taken a fork");
	pthread_mutex_lock(&(philo_data->meal));
	put_message(philo_data, philo->philo_id, "is eating");
	philo->last_philo_meal = get_time();
	pthread_mutex_unlock(&(philo_data->meal));
	time_to_sleep(philo_data->time_to_eat, philo_data);
	(philo->philo_ate)++;
	pthread_mutex_unlock(&(philo_data->forks[philo->left_fork]));
	pthread_mutex_unlock(&(philo_data->forks[philo->right_fork]));
}

void	*threading_start(void *void_philo)
{
	t_philo	*philo;
	t_data	*philo_data;

	philo = (t_philo *)void_philo;
	philo_data = philo->philo_data;
	if (philo->philo_id % 2)
		usleep(1000);
	while (!(philo_data->philo_died) && !(philo->philo_done_eating))
	{
		start_eating(philo);
		if (philo_data->n_eat != -1 && philo->philo_ate
			>= philo_data->n_eat)
		{
			philo->philo_done_eating = 1;
			break ;
		}
		if (philo_data->all_ate)
			break ;
		put_message(philo_data, philo->philo_id, "is sleeping");
		time_to_sleep(philo_data->time_to_sleep, philo_data);
		put_message(philo_data, philo->philo_id, "is thinking");
		usleep(50);
	}
	return (NULL);
}

void	check_philo_death(t_data *philo_data, t_philo *philo)
{
	int	i;
	int	count;

	while (!(philo_data->all_ate))
	{
		i = -1;
		while (++i < philo_data->n_philo && !(philo_data->philo_died))
		{
			if (time_diff(philo[i].last_philo_meal, get_time())
				>= philo_data->time_to_die && philo[i].philo_done_eating != 1)
			{
				put_message(philo_data, i, "died");
				philo_data->philo_died = 1;
			}
		}
		if (philo_data->philo_died)
			break ;
		i = -1;
		count = 0;
		while (++i < philo_data->n_philo && (philo_data->n_eat) != -1)
			if (philo[i].philo_ate >= philo_data->n_eat)
				count++;
		if (count == philo_data->n_philo)
			philo_data->all_ate = 1;
	}
}

int	start_philo(t_data *philo_data)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = philo_data->philo;
	philo_data->time_stamp = get_time();
	while (i < philo_data->n_philo)
	{
		if (pthread_create(&(philo[i].philo), NULL,
				threading_start, &(philo[i])))
			return (1);
		philo[i].last_philo_meal = get_time();
		i++;
	}
	check_philo_death(philo_data, philo_data->philo);
	join_and_destroy(philo_data);
	return (0);
}

void	join_and_destroy(t_data *philo_data)
{
	int	i;

	i = -1;
	while (++i < philo_data->n_philo)
		pthread_mutex_destroy(&(philo_data->forks[i]));
	pthread_mutex_destroy(&(philo_data->message));
	pthread_mutex_destroy(&(philo_data->meal));
}
