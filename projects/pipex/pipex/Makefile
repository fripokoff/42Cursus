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

NAME = pipex
AR = $(NAME).a
CC = gcc
RM = rm -f

CFLAGS	= -Wall -Werror -Wextra -I./inc
MLIB = ar -rcs

SRCS = src/pipex/pipex.c src/pipex/process.c src/pipex/exec.c

OBJS = $(SRCS:.c=.o)

LIBFT = src/libft
PRINTF = src/ft_printf

LIBFT_MAKE = make -s -C $(LIBFT)
LIBFT_PATH = $(LIBFT)/libft.a

PRINTF_MAKE = make -s -C $(PRINTF)
PRINTF_PATH = $(PRINTF)/ft_printf.a

all : $(NAME) $(LIBFT_PATH)


$(NAME) : $(AR) $(LIBFT_PATH) $(PRINTF_PATH)
	$(CC) $(AR) $(LIBFT_PATH) $(PRINTF_PATH) -o $(NAME)

$(AR) : $(OBJS)
	$(MLIB) $(AR) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE)

$(PRINTF_PATH) :
	$(PRINTF_MAKE)

clean :
	$(RM) $(OBJS) $(AR)
	$(LIBFT_MAKE) clean

fclean : clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean

re : fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS} ${BSRCS}
	norminette -R CheckDefine ${INCS} pipex.h

.PHONY : all clean fclean re