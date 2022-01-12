/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 20:34:17 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/12 21:52:13 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	put_error(int code)
{
	if (code == 1)
		write(2, "Wrong Amount Of Argument Try Again...\n", 39);
	if (code == 2)
		write(2, "Uknowen Error When Intializing Mutex\n", 37);
	if (code == 3)
		write(2, "There Was An Error Creating The Threads\n", 41);
	if (code == 10)
		write(2, "Number Of Times Each Philosopher Must Eat Cannot Be Negative Or Null...\n", 70);
	if (code == 20)
		write(2, "Invalide Entries... Try Again With Correct Ones...\n", 52);
	exit(-1);
}
