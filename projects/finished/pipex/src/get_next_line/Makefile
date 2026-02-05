# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpires <kpires@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/04 12:13:50 by kpires            #+#    #+#              #
#    Updated: 2024/06/13 10:48:52 by kpires           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	get_next_line.c get_next_line_utils.c\

HEADER = get_next_line.h

NAME	=	get_next_line.a

OBJ	=	$(SRC:.c=.o)

CC			= gcc
RM			= rm -rf
AR			= ar rc
RN			= ranlib

CFLAGS	+=	-Wall -Wextra -Werror -I../../inc

all: $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RN) $(NAME)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(B_SRC)
	gcc -nostartfiles -shared -o ft_printf.so $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re so
