#include "RPN.hpp"
#include <iostream>

int main(int argc, char *argv[])
{
	if (argc != 2)
	{
		std::cerr << "Error: It must have 2 arguments" << std::endl;
		return 0;
	}
	RPN a;
	a.splitToken(argv[1]);
	a.printToken();
	return 0;
}
