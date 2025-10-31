NAME = RPN
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp RPN.cpp
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

run: all
	@echo "\nRunning subject tests..."
	@echo "\nTest1: ./RPN \"8 9 * 9 - 9 - 9 - 4 - 1 +\""
	@./RPN "8 9 * 9 - 9 - 9 - 4 - 1 +"
	@echo "\nTest2: ./RPN \"7 7 * 7 -\""
	@./RPN "7 7 * 7 -"
	@echo "\nTest3: ./RPN \"1 2 * 2 / 2 * 2 4 - +\""
	@./RPN "1 2 * 2 / 2 * 2 4 - +"
	@echo "\nTest4: ./RPN \"(1 + 1)\""
	@./RPN "(1 + 1)"
	@echo "\nSubject tests completed!"

.PHONY: all clean fclean re run
