GREEN = \033[0;32m
RE = \033[0m

SRC = megaphone.cpp 

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -O3 -g

OBJ = $(SRC:.cpp=.o)
NAME =  phonebook

all:$(NAME)

$(NAME): $(OBJ)
	$(CC_FLAGS) -o $@ $<
	@echo "$(GREEN)OK$(RE)"

%.o:%.cpp phonebook.hpp
	$(CC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re