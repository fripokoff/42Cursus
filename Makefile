NAME	= libft.a

DIR_SRC	= src
DIR_OBJS	= objs
SUBDIRS		= is str mem

SRC_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_SRC)/, $(dir)))
OBJS_DIRS	= $(foreach dir, $(SUBDIRS), $(addprefix $(DIR_OBJS)/, $(dir)))
SRC		= $(foreach dir, $(SRC_DIRS), $(wildcard $(dir)/*.c))
OBJS		= $(subst $(DIR_SRC), $(DIR_OBJS), $(SRC:.c=.o))

INC	= -I inc

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
RM		= /bin/rm -f

$(DIR_OBJS)/%.o :	$(DIR_SRC)/%.c
			@mkdir -p $(DIR_OBJS) $(OBJS_DIRS)
			@$(CC) $(CFLAGS) $(INC) -c $< -o $@

all:		$(NAME)

$(NAME):	$(OBJS)
			@ar -rcs $(NAME) $(OBJS)
			@ranlib $(NAME)

clean:
			@$(RM) $(OBJS)
			@$(RM) -r $(DIR_OBJS)

fclean:		clean
			@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re