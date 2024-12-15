NAME = fileLogs

FLAGS = -Wall -Wextra -Werror -std=c++98
GG = c++
RM = rm -rf

SRC = Account.cpp test.cpp
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
