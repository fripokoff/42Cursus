# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/14 12:20:45 by apintus           #+#    #+#              #
#    Updated: 2024/02/01 15:38:41 by apintus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

####################################################
## ARGUMENTS

CC = gcc
RM = rm -f
AR = ar rc
RN = ranlib
CFLAGS = -Wall -Wextra -Werror -g

NAME = libft.a

##################################################
## SOURCES

SRCS =	ft_isalpha.c\
		ft_isdigit.c\
		ft_isalnum.c\
		ft_isascii.c\
		ft_isprint.c\
		ft_strlen.c\
		ft_memset.c\
		ft_bzero.c\
		ft_memcpy.c\
		ft_memmove.c\
		ft_strlcpy.c\
		ft_strlcat.c\
		ft_toupper.c\
		ft_tolower.c\
		ft_strchr.c\
		ft_strrchr.c\
		ft_strncmp.c\
		ft_memchr.c\
		ft_memcmp.c\
		ft_strnstr.c\
		ft_atoi.c\
		ft_calloc.c\
		ft_strdup.c\
		ft_substr.c\
		ft_strjoin.c\
		ft_strtrim.c\
		ft_split.c\
		ft_itoa.c\
		ft_strmapi.c\
		ft_striteri.c\
		ft_putchar_fd.c\
		ft_putstr_fd.c\
		ft_putendl_fd.c\
		ft_putnbr_fd.c\
		ft_printf.c\
		ft_putchar.c\
		ft_putstr.c\
		ft_utils.c\

BONUS =	ft_lstnew.c\
		ft_lstadd_front.c\
		ft_lstsize.c\
		ft_lstlast.c\
		ft_lstadd_back.c\
		ft_lstdelone.c\
		ft_lstclear.c\
		ft_lstiter.c\
		ft_lstmap.c\

GNL = get_next_line.c\
		get_next_line_utils.c\

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(BONUS:.c=.o)

GNL_OBJS = $(GNL:.c=.o)


####################################################
## RULES

all : $(NAME)

$(NAME) :
	$(CC) $(CFLAGS) -c $(SRCS) $(GNL)
	$(AR) $(NAME) $(OBJS) $(GNL_OBJS)
	$(RN) $(NAME)

bonus : $(OBJS_BONUS)
		$(AR) $(NAME) $(OBJS_BONUS)

clean :
	$(RM) $(OBJS) $(OBJS_BONUS) $(GNL_OBJS)

fclean : clean
	$(RM) $(NAME)

re : fclean all

.PHONY: all fclean clean re
