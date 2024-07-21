NAME = so_long
AR = $(NAME).a
CC = gcc
RM = rm -f

CFLAGS = -Wall -Wextra -Werror -I./inc
MLX_FLAGS = -L mlx -l mlx -I mlx -lXext -lX11 -lm -lz
SRC_PATH=src/so_long/
MLIB = ar -rcs

SRCS = so_long.c utils.c parsing.c

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

all : copy_mlx $(NAME) $(LIBFT_PATH) $(MLX_PATH) $(PRINTF_PATH) $(GNL_PATH)

$(NAME) : $(AR) $(LIBFT_PATH) $(MLX_PATH) $(PRINTF_PATH) $(GNL_PATH)
	$(CC) $(AR) $(LIBFT_PATH) $(MLX_PATH) $(PRINTF_PATH) $(GNL_PATH) -o $(NAME) $(MLX_FLAGS)
	
copy_mlx:
	cp mlx/mlx.h inc
	cp mlx/mlx_int.h inc

$(AR) : $(OBJS)
	$(MLIB) $(AR) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE)

$(MLX_PATH) :
	$(MLX_MAKE)

$(PRINTF_PATH) :
	$(PRINTF_MAKE)

$(GNL_PATH) :
	$(GNL_MAKE)

clean :
	$(RM) $(OBJS) $(AR)
	$(LIBFT_MAKE) clean
	$(MLX_MAKE) clean
	$(PRINTF_MAKE) clean
	$(GNL_MAKE) clean

fclean : clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean
	$(PRINTF_MAKE) fclean
	$(GNL_MAKE) fclean
	rm -rf $(MLX_PATH)

re : fclean all

.PHONY : all clean fclean re