/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:59:36 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/08 21:07:37 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int main(int argc, char **argv)
{
	t_data	philo_data;
	
	if (argc != 5 && argc != 6)
		exit_error(1);
	if (init_data(&philo_data, argv))
		exit_error(2);
	int total = philo_data.number_of_philo;
	if (start_philo(&philo_data))
		exit_error(5);
	// while (--total >= 0)
	// {
	// 	printf("philo id : %d has left fork: %d and right fork : %d\n",philo_data.philo[total].philo_id, philo_data.philo[total].left_fork, philo_data.philo[total].right_fork);
	// }
	return (0);
}