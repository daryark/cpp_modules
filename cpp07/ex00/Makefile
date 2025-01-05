GREEN = \033[0;32m
RE = \033[0m

SRC =  main.cpp
HDR = whatever.hpp
OBJ = $(SRC:.cpp=.o)

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -O3 -g
NAME =  whatever

all:$(NAME)

$(NAME): $(OBJ)
	$(CC_FLAGS) -o $@ $^
	@echo "$(GREEN)OK$(RE)"

%.o: %.cpp $(HDR) Makefile
	$(CC_FLAGS) -c $< -o $@

clean:
	@rm -rf *.o

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re