SRC	=	ft_bzero.c ft_strlen.c ft_strlcpy.c ft_strlcat.c ft_strjoin.c ft_striteri.c ft_putendl_fd.c\
	ft_strncmp.c ft_atoi.c ft_isdigit.c ft_isascii.c ft_calloc.c ft_strtrim.c ft_putchar_fd.c\
	ft_isprint.c ft_isalpha.c ft_isalnum.c ft_toupper.c ft_tolower.c ft_split.c ft_putstr_fd.c \
	ft_strnstr.c ft_memset.c ft_memcpy.c ft_memcmp.c ft_strdup.c ft_itoa.c ft_putnbr_fd.c\
	ft_memmove.c ft_memchr.c ft_strchr.c ft_strrchr.c ft_substr.c ft_strmapi.c\

CC	=	gcc

OBJ	=	$(SRC:.c=.o)

NAME	=	libft.a

HEADER = libft.h

CFLAGS	+=	-Wall -Wextra -Werror

RM	=	rm -rf

all: $(NAME)
	
$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
 
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

so:
	$(CC) -nostartfiles -fPIC $(CFLAGS) $(SRC)
	gcc -nostartfiles -shared -o libft.so $(OBJ)

.PHONY: all clean fclean re
