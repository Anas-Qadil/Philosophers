/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_error.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/08 17:14:40 by aqadil            #+#    #+#             */
/*   Updated: 2022/01/08 21:49:53 by aqadil           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    exit_error(int code)
{
    if (code == 1)
        write(2, "Wrong Amount Of Argument\n", 25);
    if (code == 2)
        write(2, "Failed To Init The Philosophers\n", 26);
    if (code == 3)
        write(2, "Failed To Init The Mutex\n", 26);
    if (code == 5)
        write(2, "Failed To Start The Philosophers", 32);
    exit(-1);
}

void    exit_error_v_2(int code)
{
    if (code == 20)
        write(2, "Failed To Get The Current Time\n", 32);
    exit(-1);
}