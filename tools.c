/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 16:10:32 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/09 21:45:29 by aqadil           ###   ########.fr       */
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

long long int	philo_time(void)
{
	struct timeval current_time;
	long long int result;
	
	if (gettimeofday(&current_time, NULL) == -1)
		exit_error_v_2(20);
	result = (current_time.tv_sec * 1000) + (current_time.tv_usec / 1000);
	return (result);
}

long long int time_diff(long long int old, long long int new)
{
    long long int result;

    result = new - old;
    return (result);
}

void	put_message(t_data *philo_data, int	philo_id, char *message)
{
	pthread_mutex_lock(&(philo_data->message));
	if (!(philo_data->philo_died))
	{
		printf("%lli ", philo_time() - philo_data->time_stamp);
		printf("%i ", philo_id + 1);
		printf("%s\n", message);
	}
	pthread_mutex_unlock(&(philo_data->message));
}

void	time_to_sleep(long long int time, t_data *philo_data)
{
	long long int curr_time;

	curr_time = philo_time();
	while (!(philo_data->philo_died))
	{
		if (time_diff(curr_time, philo_time() >= time))
			break ;
		usleep(50);
	}
}