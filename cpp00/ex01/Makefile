CXX = c++
NAME = phonebook
RM = rm -f
CXXFLAGS = -Wall -Wextra -Werror -std=c++98
SRC = Phonebook.cpp Phonebook_utils.cpp Contact.cpp main.cpp
OBJ = $(SRC:.cpp=.o)

all: $(NAME)

$(NAME): $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: clean
	$(RM) $(NAME)

re: fclean $(NAME)

.PHONY: all, clean, fclean, re
