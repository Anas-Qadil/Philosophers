/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:16:39 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/09 21:51:22 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int init_mutex(t_data *philo_data)
{
	int total;

	total = philo_data->number_of_philo;
	while (--total >= 0)
	{
		if (pthread_mutex_init(&(philo_data->fork[total]), NULL))
			return (1);
	}
	if (pthread_mutex_init(&(philo_data->message), NULL))
		return (1);
	if (pthread_mutex_init(&(philo_data->meal), NULL))
		return (1);
	return (0);
}

void	init_philo(t_data *philo_data)
{
	int	total;

	total = philo_data->number_of_philo;
	while (--total >= 0)
	{
		philo_data->philo[total].philo_id = total;
		philo_data->philo[total].left_fork = total;
		philo_data->philo[total].right_fork = (total + 1) % philo_data->number_of_philo;
		philo_data->philo[total].last_meal = 0;
		philo_data->philo[total].philo_ate = 0;
		philo_data->philo[total].philo_data = philo_data;
	}
}

int init_data(t_data *philo_data, char **argv)
{
	philo_data->number_of_philo = ft_atoi(argv[1]);
	philo_data->time_to_die = ft_atoi(argv[2]);
	philo_data->time_to_eat = ft_atoi(argv[3]);
	philo_data->time_to_sleep = ft_atoi(argv[4]);
	if (argv[5])
		philo_data->number_of_eat = ft_atoi(argv[5]);
	else
		philo_data->number_of_eat = -1;
	philo_data->all_ate = 0;
	philo_data->philo_died = 0;
	if (philo_data->number_of_philo < 2 || philo_data->time_to_die < 0 || philo_data->time_to_eat < 0 
		|| philo_data->time_to_sleep < 0)
		return (1);
	if (init_mutex(philo_data))
		exit_error(3);
	init_philo(philo_data);
	return (0);
}