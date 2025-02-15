NAME = Fixed

CPFALG = -Wall -Wextra -Werror -std=c++98

RM  = rm -rf

CPP = c++

SRC = main.cpp Fixed.cpp
OBJ = $(SRC:.cpp=.o)

all : $(NAME)

$(NAME) : $(OBJ)
	$(CPP) $(CPFALG) $^ -o $@

%.o:%.cpp
	$(CPP) $(CPFALG) -c $< -o $@
clean : 
	$(RM) $(OBJ)
fclean : clean
	$(RM) $(NAME);

re: fclean all

.PHONY: all clean fclean re
