/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:59:36 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/03 17:57:02 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*thread1()
{
	while (1)
	{
		printf("my turn\n");
		sleep(1);
	}
}

void	*thread2()
{
	while (1)
	{
		printf("your turn\n");
		sleep(1);
	}
}

int main(int argc, char **argv)
{
	pthread_t t1;
	pthread_t t2;

	pthread_create(&t1, NULL, &thread1, NULL);
	pthread_create(&t2, NULL, &thread2, NULL);
	
	pthread_join(t2, NULL);
	pthread_join(t1, NULL);

	return (0);
}