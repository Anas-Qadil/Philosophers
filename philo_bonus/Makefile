# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/12 20:23:57 by aqadil            #+#    #+#              #
#    Updated: 2022/01/12 20:32:57 by aqadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= philo_bonus
CC		= cc
FLAGS	= -Wall -Wextra -Werror

SRC		= philo.c
OBJ		= philo.o

HEADER	= philo.h

$(NAME)	: $(SRC) $(HEADER)
	$(CC) $(FLAGS) $(SRC) -o $(NAME)

all		: $(NAME)

clean	: 
	rm -f $(OBJ)
	
fclean	: clean
	rm -f $(NAME)

re : fclean all