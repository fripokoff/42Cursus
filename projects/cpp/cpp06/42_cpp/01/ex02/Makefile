NAME:= thisisbrain

SRC:= main
SRC:= $(addsuffix .cpp, $(SRC))
OBJ:= $(SRC:%.cpp=%.o)

CC:= c++
CFLAGS:= -Werror -Wextra -Wall -std=c++98

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re