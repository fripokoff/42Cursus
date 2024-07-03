NAME			:=	pipex

LIBPATH			:=	-L libft -l ft
LIB				:=	libft.a

INCPATH			:=	-I includes
FILES			:=	pipex.c			\
					exit_failure.c	\
					child_process.c	\
					utils.c

B_FILES			:=	pipex_bonus.c			\
					exit_failure.c			\
					child_process_bonus.c	\
					utils.c

SRCPATH			:=	src
SRC				:=	$(addprefix $(SRCPATH)/,$(FILES))
B_SRC			:=	$(addprefix $(SRCPATH)/,$(B_FILES))

OBJPATH			:=	obj
OBJ				:=	$(addprefix $(OBJPATH)/,$(FILES:.c=.o))
B_OBJ			:=	$(addprefix $(OBJPATH)/,$(B_FILES:.c=.o))

DEFAULT			:=	"\033[0m"
YELLOW			:=	"\033[0;33m"
RED				:=	"\033[0;31m"
GREEN			:=	"\033[0;32m"

CC				:=	cc

RM				:=	rm -f

CFLG			:=	-Wall -Werror -Wextra -g3

all				:	$(NAME)

$(OBJPATH)		:
					@mkdir $@

$(NAME)			:	$(OBJPATH) $(OBJ)
					@make -s -C libft
					@echo "Libft compilation..."
					@$(CC) $(OBJ) -o $(NAME) $(LIBPATH)
					@echo -n $(YELLOW)
					@echo -n "$(NAME) created"
					@echo $(GREEN)
					@sleep 0.3
					@echo "Project successfully compiled"
					@echo -n $(DEFAULT)

$(OBJPATH)/%.o	:	$(SRCPATH)/%.c
					@sleep 0.1
					@$(CC) $(CFLG) -c $< -o $@ $(INCPATH)
					@printf "%s\n" $<

.PHONY			:	all re fclean clean bonus

re				:	fclean all

bonus			:	$(OBJPATH) $(B_OBJ)
					@make -s -C libft
					@echo "Libft compilation..."
					@$(CC) $(B_OBJ) -o $(NAME) $(LIBPATH)
					@echo -n $(YELLOW)
					@echo -n "$(NAME) created"
					@echo $(GREEN)
					@sleep 0.3
					@echo "Project successfully compiled"
					@echo -n $(DEFAULT)

clean			:
					@echo -n $(RED)
					@$(RM) $(OBJ)
					@echo "Removed the object files..."
					@sleep 0.2
					@$(RM) $(B_OBJ)
					@echo "Removed the bonus_object files..."
					@sleep 0.2
					@make clean -s -C libft
					@echo -n $(DEFAULT)

fclean			:	clean
					@echo -n $(RED)
					@$(RM) $(NAME)
					@$(RM) $(LIB)
					@echo "Removed $(NAME) and $(LIB)"
					@make fclean -s -C libft
					@echo -n $(DEFAULT)
					@sleep 0.2