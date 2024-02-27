# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: apintus <apintus@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/23 17:16:05 by apintus           #+#    #+#              #
#    Updated: 2024/02/02 12:39:09 by apintus          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#########################################################
## ARGUMENTS

NAME = push_swap
BONUS_NAME = checker
ARCHIVE = push_swap.a
CC = gcc
RM = rm -f
CFLAGS = -Wall -Werror -Wextra -g
MAKE_LIB = ar -rcs

##########################################################
## SOURCES

SRCS = concatenate_arg.c\
				error.c\
				ft_split.c\
				init_stack.c\
				main.c\
				push_b_to_a.c\
				push.c\
				refresh.c\
				reverse_rotate.c\
				rotate.c\
				sort_big.c\
				sort.c\
				swap.c\
				utils_stack.c\

OBJS = $(SRCS:.c=.o)

# LIBFT
LIBFT_DIR = libft
LIBFT_MAKE_COMMAND = make -s -C $(LIBFT_DIR)
LIBFT_PATH = $(LIBFT_DIR)/libft.a

# CHECKER
CHECKER_DIR = bonus
CHECKER_PATH = $(CHECKER_DIR)/$(BONUS_NAME)
SRCS_BONUS = checker_bonus.c\
				concatenate_arg_bonus.c\
				error_bonus.c\
				init_stack_bonus.c\
				push_bonus.c\
				reverse_rotate_bonus.c\
				rotate_bonus.c\
				swap_bonus.c\
				utils_stack_bonus.c\

OBJS_BONUS = $(SRCS_BONUS:%.c=$(CHECKER_DIR)/%.o)


##########################################################
## RULES

all : $(NAME) $(LIBFT_PATH)

$(NAME) : $(ARCHIVE) $(LIBFT_PATH)
	$(CC) $(ARCHIVE) $(LIBFT_PATH) -o $(NAME)

$(ARCHIVE) : $(OBJS)
	$(MAKE_LIB) $(ARCHIVE) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE_COMMAND)

clean :
	$(RM) $(OBJS) $(ARCHIVE)
	$(RM) $(OBJS_BONUS)
	$(LIBFT_MAKE_COMMAND) clean

fclean : clean
	$(RM) $(NAME)
	$(RM) $(BONUS_NAME)
	$(LIBFT_MAKE_COMMAND) fclean

re : fclean all

bonus : $(OBJS_BONUS) $(LIBFT_PATH) $(NAME)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT_PATH) -o $(BONUS_NAME)

.PHONY : all clean fclean re bonus
