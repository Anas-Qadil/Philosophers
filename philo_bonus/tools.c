/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:34:19 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/13 17:29:02 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"


int	ft_atoi(const char *str)
{
	int	i;
	int	sign;
	int	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == ' ' || str[i] == '\n')
		i++;
	if (str[i] == '-')
		sign = -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] && str[i] >= '0' && str[i] <= '9')
	{
		result = (result * 10) + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

long long int	get_time(void)
{
	struct timeval	current_time;
	long long int result;

	gettimeofday(&current_time, NULL);
	result = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (result);
}

long long int	time_diff(long long int old, long long int new)
{
	long long int result;

	result = new - old;
	return (result);
}

void	put_message(t_data *philo_data, int id, char *message)
{
	sem_wait(philo_data->message);
	if (!(philo_data->philo_died))
	{
		printf("%lli ", get_time() - philo_data->time_stamp);
		printf("%d ", id + 1);
		printf("%s\n", message);
	}
	sem_post(philo_data->message);
}

void	time_to_sleep(int time, t_data *philo_data)
{
	long long int current_time;

	current_time = get_time();
	while (!(philo_data->philo_died))
	{
		if (time_diff(current_time, get_time()) >= time)
			break ;
		if (time_diff(current_time, get_time()) >= philo_data->time_to_die)
		{
			philo_data->philo_died = 1;
			break ;
		}
		usleep(50);
	}
}