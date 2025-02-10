Name = RefPtr

CPP = c++

CPFALG = -Wall -Werror -Wextra -std=c++98

RM = rm -rf

SRC = main.cpp

OBJ = $(SRC:.cpp=.o)

all = $(Name)

$(Name) : $(OBJ)
	$(CPP) $(CPFALG) $^ -o $@

%.o : %.cpp	
	$(CPP) $(CPFALG) -c $^ -o $@

clean :
	$(RM) $(OBJ)

fclean : clean
	$(RM) $(Name)
re: 
	fclean
	all
.PHONY: all re clean fclean