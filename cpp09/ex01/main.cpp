#include "RPN.hpp"
#include <iostream>
#include <stack>

int main()
{
	RPN a;
	std::string n1 = "a";
	std::string n2 = "3";

	a.pushValues(n1);
	a.pushValues(n2);

	a.printValues();
}
