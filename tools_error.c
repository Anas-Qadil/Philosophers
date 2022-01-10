/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:14:40 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/10 01:44:41 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

int	write_error(char *str)
{
	int len;

	len = 0;
	while (str[len])
		len++;
	write(2, "Error: ", 7);
	write(2, str, len);
	write(2, "\n", 1);
	return (1);
}

int	error_manager(int error)
{
	if (error == 1)
		return (write_error("wrong Amount Of argument"));
	if (error == 2)
		return (write_error("Uknowen error when intializing mutex"));
	return (1);
}
