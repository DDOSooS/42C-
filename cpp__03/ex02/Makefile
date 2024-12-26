NAME = fragTrap

CXX = c++

CFLAGS = -Wall -Wextra -Werror 

RM = rm -rf

SRC = main.cpp ClapTrap.cpp  ScavTrap.cpp FragTrap.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CFLAGS) $^ -o $@

%.o: %.cpp
	$(CXX) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
