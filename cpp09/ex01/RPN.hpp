#ifndef RPN_HPP
#define RPN_HPP

#include <string>
#include <stack>

class RPN
{
	private:
		std::stack<int> _stack;
		int _error;

		RPN(const RPN& other);
		RPN& operator=(const RPN& other);

	public:
		RPN();
		~RPN();

		void splitToken(const std::string value);
		void processToken(const std::string token);
		void printToken();
};

#endif
