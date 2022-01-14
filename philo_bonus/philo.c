/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:27:50 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/14 02:13:54 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	t_data	philo_data;

	if (argc != 5 && argc != 6)
		put_error(1);
	if (init_data(&philo_data, argv))
		put_error(0);
	if (start_philo(&philo_data))
		put_error(3);
	return (0);
}
