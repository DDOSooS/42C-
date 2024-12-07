NAME = phoneBook

FLAGS = -Wall -Wextra -Werror 
GG = g++
RM = rm -rf

SRC = phoneBook.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(GG) $(FLAGS) $^ -o $@

%.o: %.cpp
	$(GG) $(FLAGS) -c $< -o $@
clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all re clean fclean
