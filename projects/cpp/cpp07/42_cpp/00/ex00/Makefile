NAME:= megaphone

CC:= c++
CFLAGS:= -Werror -Wall -Wextra -std=c++98

INC:= .
SRC:= \
	Megaphone.cpp \

OBJ:= $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

debug: CFLAGS += -g3
debug: $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re