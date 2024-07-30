NAME = so_long
AR = $(NAME).a
CC = cc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I./inc
MLX_FLAGS = -L mlx -l mlx -I mlx -lXext -lX11 -lm -lz
SRC_PATH=src/so_long/
MLIB = ar -rcs

SRCS = so_long.c utils.c parsing.c pos.c check_map.c\
		window.c hooks.c moves.c build_map.c images.c\

OBJS = $(addprefix $(SRC_PATH),$(SRCS:.c=.o))

MLX = mlx
MLX_MAKE = make -s -C $(MLX)
MLX_PATH = $(MLX)/libmlx.a

LIBFT = src/libft
LIBFT_MAKE = make -s -C $(LIBFT)
LIBFT_PATH = $(LIBFT)/libft.a

PRINTF = src/ft_printf
PRINTF_MAKE = make -s -C $(PRINTF)
PRINTF_PATH = $(PRINTF)/ft_printf.a

GNL = src/get_next_line
GNL_MAKE = make -s -C $(GNL)
GNL_PATH = $(GNL)/get_next_line.a

WIDTH	:= $(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -Fx '{print $$1}')
HEIGHT	:= $(shell xdpyinfo | grep dim | awk '{print $$2}' | awk -Fx '{print $$2}')
IMGS	:= "$(shell find * | grep .xpm | grep sprites)"
MACROS	:= -DSCREEN_WIDTH=$(WIDTH) -DSCREEN_HEIGHT=$(HEIGHT) -DIMGS="\$(IMGS)\"

all : setup_mlx $(NAME)
		@echo "So_long has been successfully compiled!"

$(NAME) : $(AR) $(LIBFT_PATH) $(MLX_PATH) $(PRINTF_PATH) $(GNL_PATH)
	@echo "Linking..."
	@$(CC) $(AR) $(LIBFT_PATH) $(MLX_PATH) $(PRINTF_PATH) $(GNL_PATH) -o $(NAME) $(MLX_FLAGS) $(MACROS)
	

$(AR) : $(OBJS)
	@echo "Creating archive..."
	@$(MLIB) $(AR) $(OBJS)

%.o : %.c
	@$(CC) $(CFLAGS) -c $< -o $@ $(MACROS)

$(LIBFT_PATH) :
	@echo "Compiling libft..."
	@$(LIBFT_MAKE)

$(MLX_PATH) :
	@echo "Compiling MLX..."
	@$(MLX_MAKE) > /dev/null 2>&1

$(PRINTF_PATH) :
	@echo "Compiling ft_printf..."
	@$(PRINTF_MAKE)

$(GNL_PATH) :
	@echo "Compiling get_next_line..."
	@$(GNL_MAKE)

clean :
	@echo "Cleaning..."
	@$(RM) $(OBJS) $(AR)
	@echo "So_long Cleaned"
	@$(LIBFT_MAKE) clean
	@echo "Libft Cleaned"
	@if [ -d "mlx/obj" ]; then $(MLX_MAKE) clean > /dev/null 2>&1; fi
	@echo "Mlx Cleaned"
	@$(PRINTF_MAKE) clean
	@echo "Printf Cleaned"
	@$(GNL_MAKE) clean
	@echo "Gnl Cleaned"

fclean : clean
	@echo "Full cleaning..."
	@$(RM) $(NAME)
	@$(LIBFT_MAKE) fclean
	@$(PRINTF_MAKE) fclean
	@$(GNL_MAKE) fclean
	@if [ -d "mlx" ]; then rm -rf mlx && echo "Mlx deleted"; fi

setup_mlx:
	@echo "Cloning mlx... https://github.com/42Paris/minilibx-linux.git"
	@if [ -d "mlx" ]; then echo "Mlx already imported in the project.";else git clone --quiet https://github.com/42Paris/minilibx-linux.git mlx; fi

re : fclean all

.PHONY : all clean fclean re