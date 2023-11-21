NAME = libft.a

SRC = ft_bzero.c ft_strlen.c ft_strlcpy.c ft_strlcat.c\
	ft_strncmp.c ft_atoi.c ft_isdigit.c ft_isascii.c\
	ft_isprint.c ft_isalpha.c ft_isalnum.c ft_toupper.c ft_tolower.c\
	ft_strnstr.c ft_memset.c ft_memcpy.c ft_memcmp.c\
	ft_memmove.c ft_memchr.c ft_strchr.c ft_strrchr.c\

OBJS = ft_bzero.o ft_strlen.o ft_strlcpy.o ft_strlcat.o\
	ft_strncmp.o ft_atoi.o ft_isdigit.o ft_isascii.o\
	ft_isprint.o ft_isalpha.o ft_isalnum.o ft_toupper.o ft_tolower.o\
	ft_strnstr.o ft_memset.o ft_memcpy.o ft_memcmp.o\
	ft_memmove.o ft_memchr.o ft_strchr.o ft_strrchr.o \

FLAGS = -Wall -Wextra -Werror

CC = gcc

HEADER = libft.h

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) -c $(SRC)
	ar rc $(NAME) $(OBJS)
	ranlib $(NAME)

clean:
	rm -rf $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all