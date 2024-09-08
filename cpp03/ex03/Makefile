GREEN = \033[0;32m
RE = \033[0m

SRC =  main.cpp ClapTrap.cpp ScavTrap.cpp FragTrap.cpp DiamondTrap.cpp
HDR = ClapTrap.hpp ScavTrap.hpp FragTrap.hpp DiamondTrap.hpp

CC_FLAGS = c++ -std=c++98 -Wall -Wextra -Werror -Wshadow -Wno-shadow -pedantic -O3 -g

OBJ = $(SRC:.cpp=.o)
NAME =  DiamondTrap

all:$(NAME)

$(NAME): $(OBJ)
	$(CC_FLAGS) -o $@ $^
	@echo "$(GREEN)OK$(RE)"

%.o: %.cpp $(HDR) Makefile
	$(CC_FLAGS) -c $< -o $@

clean:
	@rm -f $(OBJ)

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re