NAME = PmergeMe
CXX = c++
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = main.cpp PmergeMe.cpp
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

test1: all
	@echo "Running subject test1..."
	@echo "./PmergeMe 3 5 9 7 4"
	@bash -c './PmergeMe 3 5 9 7 4'

test2: all
	@echo "Running subject test2..."
	@echo "./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`"
	@bash -c "./PmergeMe `shuf -i 1-100000 -n 3000 | tr "\n" " "`"

test3: all
	@echo "Running subject test3..."
	@echo './PmergeMe "-1" "2"'
	-@ bash -c './PmergeMe "-1" "2" || true'

.PHONY: all clean fclean re test1 test2 test3
