# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 20:23:57 by aqadil            #+#    #+#              #
#    Updated: 2022/01/13 00:45:27 by aqadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus
CC		= cc
FLAGS	= -Wall -Wextra -Werror

SRC		= philo.c start_philo.c tools_error.c tools.c init.c
OBJ		= philo.o start_philo.o tools_error.o tools.o init.o

HEADER	= philo.h

$(NAME)	: $(OBJ) $(HEADER)
	$(CC) $(OBJ) -o $(NAME)

%.o : %.c
	$(CC) -o $@ -c $<

all		: $(NAME)

clean	: 
	rm -f $(OBJ)
	
fclean	: clean
	rm -f $(NAME)

re : fclean all