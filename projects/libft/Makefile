# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kpires <kpires@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/29 18:17:05 by kpires            #+#    #+#              #
#    Updated: 2023/12/04 11:59:27 by kpires           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

SRC	=	ft_bzero.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strjoin.c ft_striteri.c ft_putendl_fd.c\
	ft_strncmp.c ft_atoi.c ft_isdigit.c ft_isascii.c ft_calloc.c ft_strtrim.c ft_putchar_fd.c\
	ft_isprint.c ft_isalpha.c ft_isalnum.c ft_toupper.c ft_tolower.c ft_split.c ft_putstr_fd.c \
	ft_strnstr.c ft_memset.c ft_memcpy.c ft_memcmp.c ft_strdup.c ft_itoa.c ft_putnbr_fd.c\
	ft_memmove.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_substr.c ft_strmapi.c\

B_SRC	= ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c \
	ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c\

HEADER = libft.h

NAME	=	libft.a

OBJ	=	$(SRC:.c=.o)

BONUS_O	= $(B_SRC:.c=.o)

CC			= gcc
RM			= rm -rf
AR			= ar rc
RN			= ranlib

CFLAGS	+=	-Wall -Wextra -Werror

all: $(NAME)

bonus:	$(BONUS_O)
			$(AR) $(NAME) $(BONUS_O)
			$(RN) $(NAME)

$(NAME): $(OBJ)
	$(AR) $(NAME) $(OBJ)
	$(RN) $(NAME)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ) $(BONUS_O)

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC) $(B_SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ) $(BONUS_O)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re so
