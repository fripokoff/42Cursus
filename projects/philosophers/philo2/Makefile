# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpires <kpires@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/23 11:23:47 by kpires            #+#    #+#              #
#    Updated: 2025/02/13 11:45:44 by kpires           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo
HEADER = philo.h

SRC = main.c	\
		init.c	\
		utils.c	\
		simulation.c \
		parsing.c \
		state.c
OBJ = $(SRC:.c=.o)

CC = cc
FLAGS = -Wall -Wextra -Werror
RM = rm -f

all : $(NAME)

$(NAME) : $(OBJ) $(HEADER)
		$(CC) $(FLAGS) $(OBJ) -pthread -o $(NAME)

%.o : %.c
		$(CC) $(FLAGS) -c -o $@ $^

clean :
		$(RM) $(OBJ) $(BOBJ)

fclean : clean
		$(RM) $(NAME)

re : fclean
		make all

.PHONY: all clean fclean re
