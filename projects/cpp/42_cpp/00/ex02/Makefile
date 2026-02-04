NAME:= account

CC:= c++
CFLAGS:= -Werror -Wall -Wextra -std=c++98

OBJ_PATH:= obj/
INC_PATH:= .

SRC := tests Account
SRC := $(addsuffix .cpp, $(SRC))
OBJ := $(SRC:.cpp=.o)

all: $(NAME)

debug: CFLAGS += -g3
debug: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PATH)

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re