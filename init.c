/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:16:39 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/11 01:20:15 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	init_mutex(t_data *philo_data)
{
	int i;

	i = philo_data->number_of_philo;
	while (--i >= 0)
	{
		if (pthread_mutex_init(&(philo_data->forks[i]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(philo_data->message), NULL))
		return (1);
	if (pthread_mutex_init(&(philo_data->meal), NULL))
		return (1);
	return (0);
}

int	init_philo(t_data *philo_data)
{
	int i;

	i = philo_data->number_of_philo;
	while (--i >= 0)
	{
		philo_data->philo[i].philo_id = i;
		philo_data->philo[i].philo_ate = 0;
		philo_data->philo[i].left_fork = i;
		philo_data->philo[i].right_fork = (i + 1) % philo_data->number_of_philo;
		philo_data->philo[i].last_philo_meal = 0;
		philo_data->philo[i].philo_done_eating = 0;
		philo_data->philo[i].philo_data = philo_data;
	}
	return (0);
}

int	init_data(t_data *philo_data, char **argv)
{
	philo_data->number_of_philo = ft_atoi(argv[1]);
	philo_data->time_to_die = ft_atoi(argv[2]);
	philo_data->time_to_eat = ft_atoi(argv[3]);
	philo_data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
	{
		if (ft_atoi(argv[5]) < 1)
			put_error(10);
		else
			philo_data->number_of_eat = ft_atoi(argv[5]);
	}
	else
		philo_data->number_of_eat = -1;
	philo_data->all_ate = 0;
	philo_data->philo_died = 0;
	if (philo_data->number_of_philo < 1 || philo_data->time_to_die < 0 || philo_data->time_to_eat < 0
		|| philo_data->time_to_sleep < 0)
		put_error(20);
	if (init_mutex(philo_data))
		return (1);
	init_philo(philo_data);
	return (0);
}
