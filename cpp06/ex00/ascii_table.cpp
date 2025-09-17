#include <iostream>
#include <iomanip>
#include <cctype>

void create_lines(int num)
{
	int i = -1;
	while (++i < num)
		std::cout << std::endl;
}

int main()
{
	int width = 4;
	
	create_lines(1);
	std::cout << std::setw(5) << "Dec" << std::setw(5) << "Hex" << std::setw(6) << " Val |";
	for (int i = 0; i < 7; i++)
		std::cout << std::setw(4) << "Dec" << std::setw(4) << "Hex" << std::setw(6) << " Val |";
	std::cout << std::endl;
	for (int i = 0; i < 8 * 14 + 1; i++)
		std::cout << "-";
	std::cout << std::endl;
	
	for (int i = 0; i < 128; i++)
	{
		std::cout << std::setw(5) << i << std::setw(5) << std::hex << i << std::dec;
		if (i == 0) std::cout << std::setw(width) << "\\0";
		else if (i == 7) std::cout << std::setw(width) << "\\a";
		else if (i == 8) std::cout << std::setw(width) << "\\b";
		else if (i == 9) std::cout << std::setw(width) << "\\t";
		else if (i == 10) std::cout << std::setw(width) << "\\n";
		else if (i == 11) std::cout << std::setw(width) << "\\v";
		else if (i == 12) std::cout << std::setw(width) << "\\f";
		else if (i == 13) std::cout << std::setw(width) << "\\r";
		else if (i == 27) std::cout << std::setw(width) << "\\e";
		else if (i >= 32 && i <= 126) std::cout << std::setw(width) << static_cast<char>(i);
		else if (i == 127) std::cout << std::setw(width) << "DEL";
		else std::cout << std::setw(width) << "NP";
		if ((i + 1) % 8 == 0)
			std::cout << "\n";
	}
	create_lines(2);
	std::cout << "  NP -> Non printable characters" << std::endl;
	create_lines(2);
	return 0;
}
