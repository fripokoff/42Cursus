# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpires <kpires@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/01/24 11:09:50 by kpires            #+#    #+#              #
#    Updated: 2024/01/24 12:50:18 by kpires           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = pipex

LIBFT = libft.a

DIR_SRC = src

DIR_OBJ = obj

SRC_NAMES = main.c

OBJ_NAMES = ${SRC_NAMES:.c=.o}

DEP = ${SRC_NAMES:.c=.d}

SRC = $(addprefix $(DIR_SRC)/, $(SRC_NAMES))

OBJ = $(addprefix $(DIR_OBJ)/, $(OBJ_NAMES))

INC	 = -Iinclude -Ilibft/Iinclude

LIB = -Llibft -lft

CC = cc

CFLAGS = -g3 -Wall -Wextra -Werror

CDFLAGS = -MMD -MP


all: ${NAME}

$(NAME): $(DIR_OBJ) $(OBJ)
	make -C libft
	$(CC) $(CFLAGS) ${INC} $(CDFLAGS) $(OBJ) $(LIB) -o $(NAME)
	@echo "Pipex"

$(OBJ): $(DIR_OBJ)/%.o : $(DIR_SRC)/%.c
	$(CC) $(CFLAGS) $(CDFLAGS) $(INC) -c $< -o $@

$(DIR_OBJ):
	mkdir -p $(DIR_OBJ)

clean:
	make clean -C libft
	rm -rf ${DIR_OBJ}

fclean: clean
	make fclean -C libft
	rm -rf ${LIBFT}
	rm -rf ${NAME}

re: fclean all

-include $(DEPS)

.PHONY: all clean fclean re