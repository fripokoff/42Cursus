NAME:= moarbrainz

CC:= c++
CFLAGS:= -Werror -Wall -Wextra -std=c++98

SRC_PATH:= src/
OBJ_PATH:= obj/
INC_PATH:= inc/

SRC:= main zombieHorde Zombie
SRC:= $(addsuffix .cpp, $(addprefix $(SRC_PATH), $(SRC)))
OBJ:= $(SRC:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)

all: $(NAME)

debug: CFLAGS += -g3
debug: $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re