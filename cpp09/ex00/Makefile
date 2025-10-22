NAME = bit
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp BitcoinExchange.cpp
OBJ = $(SRC:.cpp=.o)
RM = rm -f
all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re

#If you’re compiling .cpp → .o, make automatically uses $(CXX) and $(CXXFLAGS).

#If you’re compiling .c → .o, it uses $(CC) and $(CFLAGS).

#If you use CC in a C++ project, you’re overriding the C compiler variable,
#and make may not correctly apply its implicit rules for .cpp files — or worse,
#it might treat your .cpp files as C files depending on the environment.
