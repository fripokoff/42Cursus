# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpires <kpires@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 18:17:05 by kpires            #+#    #+#              #
#    Updated: 2024/01/24 12:57:51 by kpires           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_bzero.c ft_calloc.c ft_functions.c ft_printf.c ft_putstr_fd.c \
	ft_split.c ft_strchr.c ft_strcmp.c ft_strdup.c ft_strjoin.c ft_strlcat.c \
	ft_strlcpy.c ft_strlen.c ft_strncmp.c ft_substr.c \
	ft_get_next_line.c ft_get_next_line_utils.c ft_memset.c

NAME	=	libft.a

OBJ	=	$(SRC:.c=.o)

CC			= gcc
RM			= rm -f
AR			= ar rcs
RN			= ranlib

CFLAGS	+=	-Wall -Wextra -Werror

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)

all: $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
