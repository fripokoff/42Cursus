NAME = pipex
AR = $(NAME).a
CC = gcc
RM = rm -f

CFLAGS	= -Wall -Werror -Wextra -I./inc -g
MLIB = ar -rcs

SRCS = src/pipex/pipex.c src/pipex/process.c src/pipex/exec.c

OBJS = $(SRCS:.c=.o)

LIBFT = src/libft

LIBFT_MAKE = make -s -C $(LIBFT)
LIBFT_PATH = $(LIBFT)/libft.a

all : $(NAME) $(LIBFT_PATH)


$(NAME) : $(AR) $(LIBFT_PATH)
	$(CC) $(AR) $(LIBFT_PATH) -o $(NAME)

$(AR) : $(OBJS)
	$(MLIB) $(AR) $(OBJS)

%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBFT_PATH) :
	$(LIBFT_MAKE)

clean :
	$(RM) $(OBJS) $(AR)
	$(LIBFT_MAKE) clean

fclean : clean
	$(RM) $(NAME)
	$(LIBFT_MAKE) fclean

re : fclean all

norm:
	norminette -R CheckForbiddenSourceHeader ${SRCS}
	norminette -R CheckDefine ${INCS} ./inc/pipex.h

.PHONY : all clean fclean re