#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;

	public:
		RPN();
		~RPN();

		void pushValues(const std::string value);
		void printValues();
};

#endif
