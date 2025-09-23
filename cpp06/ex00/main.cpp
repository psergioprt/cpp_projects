#include <iostream>
#include <string>

#include "ScalarConverter.hpp"

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " Literal" << std::endl;
		return 1;
	}
	ScalarConverter::Type type;
	ScalarConverter::convert(argv[1], type);
	return 0;
}
