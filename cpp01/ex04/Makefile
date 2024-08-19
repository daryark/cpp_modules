GREEN = \033[0;32m
RE = \033[0m

SRC =  main.cpp

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -O3 -g

OBJ = $(SRC:.cpp=.o)
NAME =  string_replace

all:$(NAME)

$(NAME): $(OBJ)
	$(CC_FLAGS) -o $@ $^
	@echo "$(GREEN)OK$(RE)"

%.o: %.cpp Makefile
	$(CC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)
	@rm -f *.replace

re:	fclean all

.PHONY:	all clean fclean re