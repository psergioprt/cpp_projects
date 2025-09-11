#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const std::string& str);
		~ScalarConverter();
	public:
		static void convert(std::string& str);
};

#endif
