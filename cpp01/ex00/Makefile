GREEN = \033[0;32m
RED = \033[0;31m
RE = \033[0m

SRC =  main.cpp Zombie.cpp newZombie.cpp randomChump.cpp
HDR = Zombie.hpp

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -O3 -g

OBJ = $(SRC:.cpp=.o)
NAME =  zombie

all:$(NAME)

$(NAME): $(OBJ)
	$(CC_FLAGS) -o $@ $^
	@echo "$(GREEN)OK$(RE)"

%.o: %.cpp $(HDR) Makefile
	$(CC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)
	@echo "$(RED)clean$(RE)"

fclean:	clean
	@rm -f $(NAME)
	@echo "$(RED)fclean$(RE)"


re:	fclean all

.PHONY:	all clean fclean re