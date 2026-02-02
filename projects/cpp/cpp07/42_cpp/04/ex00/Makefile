NAME := a.out

CC := c++
FILE_TYPE := cpp
CFLAGS := -Werror -Wall -Wextra -std=c++98 -MMD -MP

SRC_PATH := src/
OBJ_PATH := obj/
INC_PATH := inc/

SRC_FILES := Animal Dog Cat WrongAnimal WrongCat main
SRC := $(patsubst %,$(SRC_PATH)%.$(FILE_TYPE), $(SRC_FILES))
OBJ := $(patsubst %,$(OBJ_PATH)%.o,$(SRC_FILES))
DEP := $(OBJ:.o=.d)

all: $(NAME)
	@echo "UwU, youw pwogwam is weady! (*^ω^*)"

debug: CFLAGS += -g3
debug: re
	@echo "(•◡•) / Youw debuggable pwogwam is weady! UwU"

$(NAME): $(OBJ_PATH) $(OBJ)
	@$(CC) $(OBJ) -o $(NAME)
	@echo "(✿◠‿◠) Success! Enjoy youw executabwe, UwU."

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)
	@echo "(⁄ ⁄•⁄ω⁄•⁄ ⁄) Making diwectowy fow objects, OwO"

-include $(DEP)

$(OBJ_PATH)%.o: $(SRC_PATH)%.cpp
	@$(CC) $(CFLAGS) -c $< -o $@ -I$(INC_PATH)
	@echo "(≧◡≦) Compiling $< into $@ UwU"

clean:
	@rm -rf $(OBJ_PATH)
	@echo "(´・ω・｀) Cweaning up objects and dependencies..."

fclean: clean
	@rm -f $(NAME)
	@echo "(ಥ﹏ಥ) All gone! Executable has been wiped."

re: fclean all
	@echo "(＾▽＾) Refweshing the buiwld, UwU"

.PHONY: all debug clean fclean re
