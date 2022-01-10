/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/01 16:59:36 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/10 01:45:20 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int		main(int argc, char **argv)
{
	t_data	philo_data;
	int		ret;

	if (argc != 5 && argc != 6)
		return (write_error("Wrong amount of arguments"));
	if ((ret = init_data(&philo_data, argv)))
		return (error_manager(ret));
	if (start_philo(&philo_data))
		return (write_error("There was an error creating the threads"));
	return (0);
}
