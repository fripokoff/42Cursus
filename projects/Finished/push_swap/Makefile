# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpires <kpires@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/02/13 09:53:08 by kpires            #+#    #+#              #
#    Updated: 2024/02/13 09:53:08 by kpires           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
AR = $(NAME).a
CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I./inc
MLIB = ar -rcs

SRCS = src/push_swap/push_swap.c\
		src/push_swap/errors.c\
		src/push_swap/process_arg.c\
		src/push_swap/init_node.c\
		src/push_swap/head_tail.c\
		src/push_swap/sort.c\
		src/push_swap/rules.c\
		src/push_swap/algo.c\
		src/push_swap/algo_utils.c

OBJS = $(SRCS:.c=.o)

LIBFT = src/libft
LIBFT_MAKE = make -s -C $(LIBFT)
LIBFT_PATH = $(LIBFT)/libft.a

all : $(NAME) $(LIBFT_PATH)

$(NAME) : $(AR) $(LIBFT_PATH)
	$(CC) $(AR) $(LIBFT_PATH) -o $(NAME)

$(AR) : $(OBJS)
	$(MLIB) $(AR) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE)

clean :
	$(RM) $(OBJS) $(AR)
	$(LIBFT_MAKE) clean

fclean : clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean

re : fclean all

.PHONY : all clean fclean re