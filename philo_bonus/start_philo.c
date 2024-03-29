/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_philo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:34:15 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/14 17:38:40 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h" 

void	start_eating(t_philo *philo)
{
	t_data	*philo_data;

	philo_data = philo->philo_data;
	sem_wait(philo_data->forks);
	put_message(philo_data, philo->philo_id, "has taken a fork");
	sem_wait(philo_data->forks);
	put_message(philo_data, philo->philo_id, "has taken a fork");
	sem_wait(philo_data->meal);
	put_message(philo_data, philo->philo_id, "is eating");
	philo->last_philo_meal = get_time();
	sem_post(philo_data->meal);
	time_to_sleep(philo_data->time_to_eat, philo_data);
	(philo->philo_ate)++;
	sem_post(philo_data->forks);
	sem_post(philo_data->forks);
}

void	start_process(t_philo *philo)
{
	t_data	*philo_data;

	philo_data = philo->philo_data;
	philo->last_philo_meal = get_time();
	pthread_create(&(philo->philo_thread), NULL, night_watch, philo);
	if (philo->philo_id % 2)
		usleep(1000);
	while (!(philo_data->philo_died) && !(philo->philo_done_eating))
	{
		start_eating(philo);
		if (philo_data->number_of_eat != -1 && philo->philo_ate
			>= philo_data->number_of_eat)
		{
			philo->philo_done_eating = 1;
			break ;
		}
		put_message(philo_data, philo->philo_id, "is sleeping");
		time_to_sleep(philo_data->time_to_sleep, philo_data);
		put_message(philo_data, philo->philo_id, "is thinking");
		usleep(50);
	}
	pthread_join(philo->philo_thread, NULL);
	if (philo_data->philo_died)
		exit(1);
	exit(0);
}

int	start_philo(t_data *philo_data)
{
	int		index;
	t_philo	*philo;

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
	close_things(philo_data);
	return (0);
}

void	close_things(t_data *philo_data)
{
	int	i;
	int j;

	i = -1;
	while (++i < philo_data->number_of_philo)
	{
		waitpid(-1, &j, 0);
		if (j != 0)
		{
			i = -1;
			while (++i < philo_data->number_of_philo)
				kill(philo_data->philo[i].process_id, 15);
			break ;
		}
	}	
	sem_close(philo_data->forks);
	sem_close(philo_data->message);
	sem_close(philo_data->meal);
	sem_unlink("/forks");
	sem_unlink("/message");
	sem_unlink("/meal");
}

void	*night_watch(void *arg_philo)
{
	t_philo	*philo;
	t_data	*philo_data;

	philo = (t_philo *)arg_philo;
	philo_data = philo->philo_data;
	while (1)
	{
		if (philo->philo_done_eating == 1)
			break ;
		if (time_diff(philo->last_philo_meal, get_time())
			> philo_data->time_to_die)
		{
			sem_wait(philo_data->meal);
			put_message(philo_data, philo->philo_id, "died");
			philo_data->philo_died = 1;
			sem_post(philo_data->meal);
			sem_wait(philo_data->message);
			exit(1);
		}
		usleep(1000);
	}
	return (NULL);
}
