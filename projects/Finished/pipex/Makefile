NAME = pipex
AR = $(NAME).a
CC = gcc
RM = rm -f

CFLAGS	= -Wall -Werror -Wextra -I./inc -g
MLIB = ar -rcs

SRCS = src/pipex/pipex.c src/pipex/process.c src/pipex/exec.c

OBJS = $(SRCS:.c=.o)

LIBFT = src/libft
PRINTF = src/ft_printf
GNL = src/get_next_line

LIBFT_MAKE = make -s -C $(LIBFT)
LIBFT_PATH = $(LIBFT)/libft.a

PRINTF_MAKE = make -s -C $(PRINTF)
PRINTF_PATH = $(PRINTF)/ft_printf.a

GNL_MAKE = make -s -C $(GNL)
GNL_PATH = $(GNL)/get_next_line.a

all : $(NAME) $(LIBFT_PATH) $(PRINTF_PATH) $(GNL_PATH)


$(NAME) : $(AR) $(LIBFT_PATH) $(PRINTF_PATH) $(GNL_PATH)
	$(CC) $(AR) $(LIBFT_PATH) $(PRINTF_PATH) $(GNL_PATH) -o $(NAME)

$(AR) : $(OBJS)
	$(MLIB) $(AR) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE)

$(PRINTF_PATH) :
	$(PRINTF_MAKE)

$(GNL_PATH) :
	$(GNL_MAKE)

clean :
	$(RM) $(OBJS) $(AR)
	$(LIBFT_MAKE) clean

fclean : clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean
	$(PRINTF_MAKE) fclean
	$(GNL_MAKE) fclean

re : fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCS} ./inc/pipex.h

.PHONY : all clean fclean re