NAME := PmergeMe

CC := c++
FILE_TYPE := cpp
CFLAGS := -Werror -Wall -Wextra -std=c++98 -MMD -MP

SRC_PATH := src/
OBJ_PATH := obj/
INC_PATH := inc/

SRC_FILES := PmergeMe main
SRC := $(patsubst %,$(SRC_PATH)%.$(FILE_TYPE), $(SRC_FILES))
OBJ := $(patsubst %,$(OBJ_PATH)%.o,$(SRC_FILES))
DEP := $(OBJ:.o=.d)

all: $(NAME)

debug: CFLAGS += -g3
debug: re

$(NAME): $(OBJ_PATH) $(OBJ)
	$(CC) $(OBJ) -o $(NAME)

$(OBJ_PATH):
	mkdir -p $(OBJ_PATH)

-include $(DEP)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PATH)

clean:
	rm -rf $(OBJ_PATH)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all debug clean fclean re
