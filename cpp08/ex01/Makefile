GREEN = \033[0;32m
RE = \033[0m

SRC =  main.cpp Span.cpp
HDR = Span.hpp
OBJ = $(SRC:.cpp=.o)

CXX = c++
CXXFLAGS = -std=c++98 -Wall -Wextra -Werror -O3 -g
NAME =  span

all:$(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $^
	@echo "$(GREEN)OK$(RE)"

%.o: %.cpp $(HDR) Makefile
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	@rm -rf *.o

fclean:	clean
	@rm -f $(NAME)

re:	fclean all

.PHONY:	all clean fclean re