#include <iostream>
#include "test10.hpp"

Example::Example()
{
	value = 42;
	std::cout << "Constructor called! Value initialized to " << value << std::endl;
}
