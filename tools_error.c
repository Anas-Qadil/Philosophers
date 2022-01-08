/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:14:40 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/08 17:48:51 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    exit_error(int code)
{
    if (code == 1)
        write(2, "Wrong Amount Of Argument\n", 25);
    if (code == 2)
        write(2, "Failed To Init The Philos\n", 26);
    if (code == 3)
        write(2, "Failed To Init The Mutex\n", 26);
    if (code == 4)
        write(2, "Faile To Init P\n", 21);
    exit(-1);
}