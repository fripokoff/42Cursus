NAME			:=	so_long

INC_PATH		:=	inc

LIB_PATH		:=	libft
LIB_FILE		:=	libft.a
LIB				:=	$(addprefix $(LIB_PATH)/,$(LIB_FILE))
INC_LIB			:=	-L $(LIB_PATH) -lft

MLX_TGZ			:=	mlx.tgz
MLX_PATH		:=	mlx
MLX_FILE		:=	libmlx.a
MLX				:=	$(addprefix $(MLX_PATH)/, $(MLX_FILE))
INC_MLX			:=	-L $(MLX_PATH) -lmlx -lXext -lX11

SRC_PATH		:=	src
SRC_FILES		:=	main.c			\
					parsing.c		\
					coords.c		\
					utils.c			\
					window.c		\
					image.c			\
					put_map.c		\
					event.c			\
					move.c			\
					path_finding.c
SRC				:=	$(addprefix $(SRC_PATH)/,$(SRC_FILES))

SRC_PATH_BONUS	:=	src_bonus
SRC_FILES_BONUS	:=	main.c			\
					parsing.c		\
					move_ghosts.c	\
					coords.c		\
					utils.c			\
					window.c		\
					image.c			\
					put_map.c		\
					event.c			\
					move.c			\
					path_finding.c
SRC_BONUS		:=	$(addprefix $(SRC_PATH_BONUS)/,$(SRC_FILES_BONUS))

OBJ_PATH		:=	obj
OBJ_FILES		:=	$(SRC_FILES:.c=.o)
OBJ				:=	$(addprefix $(OBJ_PATH)/,$(OBJ_FILES))

OBJ_PATH_BONUS	:=	obj_bonus
OBJ_FILES_BONUS	:=	$(SRC_FILES_BONUS:.c=.o)
OBJ_BONUS		:=	$(addprefix $(OBJ_PATH_BONUS)/,$(OBJ_FILES_BONUS))

RM				:=	rm -f
CC_FLGS			:=	cc -Wall -Werror -Wextra -g3

LEN		:= $(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -Fx '{print $$1}')
WID		:= $(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -Fx '{print $$2}')
IMGS	:= "$(shell find * | grep .xpm | grep sprites)"
MACROS	:= -DSCR_LEN=$(LEN) -DSCR_WID=$(WID) -DIMGS="\$(IMGS)\"

all				:	$(NAME)

.PHONY			:	all clean fclean re bonus

$(NAME)			:	$(LIB) $(MLX) $(OBJ_PATH) $(OBJ)
					@echo -n "$(GREEN)"
					@$(CC_FLGS) $(OBJ) -o $(NAME) $(INC_LIB) $(INC_MLX) $(MACROS)
					@echo $@ "has been created !$(NO_COLOR)"

bonus			:	$(LIB) $(MLX_PATH) $(MLX) $(OBJ_PATH_BONUS) $(OBJ_BONUS)
					@echo -n "$(GREEN)"
					@$(CC_FLGS) $(OBJ_BONUS) -o $(NAME) $(INC_LIB) $(INC_MLX) $(MACROS)
					@echo $@ "has been created !$(NO_COLOR)"

$(MLX)			:	$(MLX_PATH)
					@echo "$(BLUE)Compiling the mlx...$(NO_COLOR)"
					@make --no-print-directory --silent -C mlx

$(MLX_PATH)		:	$(MLX_TGZ)
					@echo "$(YELLOW)Extracting the mlx, creating the mlx...$(NO_COLOR)"
					@tar -x -f $(MLX_TGZ) && mv minilibx-linux $(MLX_PATH)

$(OBJ_PATH)/%.o	:	$(SRC_PATH)/%.c
					@echo "$(BLUE)Compiling $@$(NO_COLOR)"
					@$(CC_FLGS) -c $< -o $@ -I $(INC_PATH) $(MACROS)

$(OBJ_PATH_BONUS)/%.o	:	$(SRC_PATH_BONUS)/%.c
							@echo "$(BLUE)Compiling $@$(NO_COLOR)"
							@$(CC_FLGS) -c $< -o $@ -I $(INC_PATH) $(MACROS)

$(OBJ_PATH)		:
					@mkdir $@
$(OBJ_PATH_BONUS)	:
						@mkdir $@

$(LIB)			:
					@make --no-print-directory -C libft
					@echo "$(YELLOW)Compiling the libft...$(NO_COLOR)"

clean			:
					@$(RM) $(OBJ) $(OBJ_BONUS)
					@echo "$(RED)Deleting objects files...$(NO_COLOR)"
					@echo "$(RED)Cleaning the libft folder...$(NO_COLOR)"
					@make clean --no-print-directory -C libft

fclean			:	clean
					@rm -rf $(OBJ_PATH) $(OBJ_PATH_BONUS)
					@$(RM) $(NAME) $(LIB)
					@echo "$(RED)Deleting so_long and the libft.a...$(NO_COLOR)"
					@$(RM) -r $(MLX_PATH)
					@echo "$(RED)Deleting the mlx folder...$(NO_COLOR)"

re				:	fclean all

NO_COLOR		:=	\033[0m
BLACK			:=	\033[0;30m
BLUE			:=	\033[0;34m
GREEN			:=	\033[0;32m
CYAN			:=	\033[0;36m	
RED				:=	\033[0;31m
PURPLE			:=	\033[0;35m
YELLOW			:=	\033[0;33m
GRAY			:=	\033[0;37m