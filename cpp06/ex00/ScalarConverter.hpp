#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <string>

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(const std::string& str);
		ScalarConverter(const ScalarConverter& other);
		ScalarConverter& operator=(const ScalarConverter& other);
		~ScalarConverter();
	public:
		enum Type
		{
			UNKNOWN,
			CHAR,
			INT,
			FLOAT,
			DOUBLE
		};
		static void convert(const std::string& str, Type &type);
};

#endif
