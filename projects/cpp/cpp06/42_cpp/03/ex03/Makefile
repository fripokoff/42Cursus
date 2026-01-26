NAME:= diamondtrap

CC:= c++
CFLAGS:= -Werror -Wall -Wextra -std=c++98 -MMD -MP

SRC_PATH:= ./
OBJ_PATH:= ./
INC_PATH:= .

SRC:= main ClapTrap ScavTrap FragTrap DiamondTrap
SRC:= $(addsuffix .cpp, $(addprefix $(SRC_PATH), $(SRC)))
OBJ:= $(SRC:$(SRC_PATH)%.cpp=$(OBJ_PATH)%.o)
DEP:= $(OBJ:.o=.d)

all: $(NAME)

debug: CFLAGS += -g3
debug: fclean $(NAME)

$(NAME): $(OBJ_PATH) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir $(OBJ_PATH)

-include $(DEP)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PATH)

clean:
	rm -f $(OBJ) $(DEP)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
