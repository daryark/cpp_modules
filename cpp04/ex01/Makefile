GREEN = \033[0;32m
RE = \033[0m

SRC =  main.cpp Animal.cpp Cat.cpp Dog.cpp Brain.cpp
HDR = Animal.hpp Cat.hpp Dog.hpp Brain.hpp
OBJ = $(addprefix $(OBJ_F), $(SRC:%.cpp=%.o))
OBJ_F = obj/

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow -pedantic -O3 -g
NAME =  Animal

all:$(NAME)

$(NAME): $(OBJ)
	$(CC_FLAGS) -o $@ $^
	@echo "$(GREEN)OK$(RE)"

$(OBJ_F)%.o: %.cpp $(HDR) Makefile
	mkdir -p $(@D)
	$(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf $(OBJ_F)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re