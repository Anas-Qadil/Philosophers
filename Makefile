# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: aqadil <aqadil@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/01 17:32:28 by aqadil            #+#    #+#              #
#    Updated: 2022/01/01 17:50:10 by aqadil           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		= philo
CC			= cc
SRCS		= philo.c
OBJS		= philo.o

HEADER = philo.h

$(NAME): $(OBJS) $(HEADER)
	$(CC) $(OBJS) -o $(NAME)

%.o : %.c
	$(CC) -o $@ -c $<

all: $(NAME)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all