/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:59:36 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/07 18:19:33 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

pthread_mutex_t mutex;


void	*my_turn(void *args)
{
	int j = 0;
	int *i = (int *)args;
	while (j < 10000000)
	{
		pthread_mutex_lock(&mutex);
		(*i)++;
		j++;
		pthread_mutex_unlock(&mutex);
	}
	return (NULL);
}


int main()
{
	pthread_t	t1;
	pthread_t	t2;
	int	*arg;
	int	i = 0;
	pthread_mutex_init(&mutex, NULL);
	
	
	pthread_create(&t1, NULL, &my_turn, &i);
	pthread_create(&t2, NULL, &my_turn, &i);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);

	pthread_mutex_destroy(&mutex);
	
	printf("%d",i);
	return (0);
}