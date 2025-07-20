NAME = cub3D
CC = cc
CFLAGS = -Wall -Wextra -Werror -g3

SRC_PATH = src/
SRC = main.c \
	utils/clean.c \
	utils/mlx_utils.c \
	player/inputs.c \
	player/movements.c \
	ray/ray_casting.c \
	ray/env_render.c \
	ray/dda.c \
	map/init.c \
	parsing/gest_err.c\
	parsing/gest_id.c\
	parsing/parsing.c\
	parsing/str2arr.c\
	parsing/utils.c \
	parsing/fill_struct.c\
	parsing/gest_map.c\
	lib/ft_calloc.c\
	lib/ft_realloc.c\
	lib/ft_strcmp.c\
	lib/ft_strlen.c\
	lib/ft_strchr.c\
	lib/ft_strdup.c\
	lib/fd_putstr.c\
	lib/ft_strncmp.c\

SRCS = $(addprefix $(SRC_PATH), $(SRC))
OBJ_PATH = obj/
OBJ = $(SRC:.c=.o)
OBJS = $(addprefix $(OBJ_PATH), $(OBJ))

# MLX
MLX_PATH = includes/mlx/
MLX_NAME = libmlx.a
MLX = $(MLX_PATH)$(MLX_NAME)

# Flags
LFLAGS = -L$(MLX_PATH) -lmlx -lXext -lX11 -lm -lz
INC = -I./includes/

# Colors
GREEN = \033[0;32m
YELLOW = \033[0;33m
RED = \033[0;31m
BLUE = \033[0;34m
NC = \033[0m

all: $(OBJ_PATH) $(MLX) $(NAME)

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@mkdir -p $(OBJ_PATH)/utils
	@mkdir -p $(OBJ_PATH)/player
	@mkdir -p $(OBJ_PATH)/ray
	@mkdir -p $(OBJ_PATH)/map
	@mkdir -p $(OBJ_PATH)/parsing
	@mkdir -p $(OBJ_PATH)/lib

$(MLX):
	@if [ ! -d "$(MLX_PATH)" ]; then \
		printf "$(BLUE)[MINILIBX]$(NC)\n"; \
		printf "$(BLUE)⌛ Installing minilibx...$(NC)\n"; \
		git clone -q https://github.com/42Paris/minilibx-linux.git $(MLX_PATH) && \
		printf "  └$(BLUE)⚙️ Compiling minilibx...$(NC)\n"; \
		make -C $(MLX_PATH) > /dev/null 2>&1 && \
		printf "    └$(GREEN)✅ minilibx installed!$(NC)\n"; \
	elif [ ! -f "$(MLX)" ]; then \
		printf "$(BLUE)⚙️  Compiling minilibx...$(NC)\n"; \
		make -C $(MLX_PATH) > /dev/null 2>&1 && \
		printf "$(GREEN)✅ minilibx compiled!$(NC)\n"; \
	fi

$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@printf "\033[2K\r$(BLUE)⌛ Compilation: $<$(NC)"
	@$(CC) $(CFLAGS) $(INC) -c $< -o $@

$(NAME): $(OBJS)
	@printf "\n$(BLUE)[CUB3D]$(NC)\n"
	@printf "  └$(BLUE)⚙️  Linking $(NAME)...$(NC)\n"
	@$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LFLAGS)
	@printf "   └$(GREEN)✅ $(NAME) created!$(NC)\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⢀⡀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⣀⣤⣴⣾⣿⣿⣷⣦⣤⣀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⢀⣠⣴⣾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣷⣦⣄⡀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠰⢾⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡷⠆⠀⠀⠀\n"
	@printf "⠀⠀⢸⣷⣦⣈⠙⠛⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠛⠋⣁⣴⣾⡇⠀⠀\n"
	@printf "⠀⠀⢸⣿⣿⣿⣿⣷⣦⣄⣉⠛⠻⢿⣿⣿⡿⠟⠛⣉⣠⣴⣾⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣶⣤⡌⢡⣤⣶⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "⠀⠀⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⠀⠀\n"
	@printf "⠀⠀⠘⠿⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⣿⣿⣿⣿⠿⠃⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠉⠛⠿⣿⣿⣿⣿⣿⣿⡇⢸⣿⣿⣿⣿⣿⣿⠿⠛⠉⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠈⠙⠛⠿⣿⡇⢸⣿⠿⠛⠋⠁⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠁⠈⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀⠀\n"
	@printf "  $(RED)C U B 3 D  C O M P I L E D$(NC)\n"
	@printf "    @the01rch 🤝 @fripok\n"

clean:
	@printf "\n🗑️  Removing object files...\n"
	@rm -rf $(OBJ_PATH)
	@if [ -d "$(MLX_PATH)" ]; then \
		printf "$(YELLOW)🧹 Cleaning mlx$(NC)\n"; \
		make clean -C $(MLX_PATH) > /dev/null 2>&1; \
		printf "  └$(GREEN)✅ mlx cleaned!$(NC)\n"; \
	fi
	@printf "$(GREEN)✅ Cleaning completed!$(NC)\n\n"

norm:
	@printf "$(BLUE)📋 Checking norm...$(NC)\n"
	@norminette includes/cub3d.h
	@norminette $(SRC_PATH)
	@printf "$(GREEN)✅ Check completed!$(NC)\n"

fclean: clean
	@printf "🗑️  Removing the executable $(NAME)...\n"
	@rm -rf $(NAME)
	@printf "  └$(GREEN)✅ Executable removed!$(NC)\n"
	@printf "\n$(GREEN)✅ Full cleaning completed!$(NC)\n\n"

re: fclean all

.PHONY: all clean fclean re norm
