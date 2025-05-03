#include <fstream>
#include <iostream>
#include <string>

std::string	replaceAll(const std::string& line, const std::string& s1, const std::string& s2)
{
	std::string	result;
	size_t		pos = 0;
	size_t		found;

	while ((found = line.find(s1, pos)) != std::string::npos)
	{
		result.append(line, pos, found - pos);
		result.append(s2);
		pos = found + s1.length();
	}
	result.append(line, pos);
	return (result);
}

int	main(int argc, char *argv[])
{
	if (argc != 4)
	{
		std::cerr << "Usage: ./replace <filename> <s1> <s2>" << std::endl;
		return (1);
	}
	std::string filename = argv[1];
	std::string s1 = argv[2];
	std::string s2 = argv[3];
	if (s1.empty())
	{
		std::cerr << "Error: s1 must not be empty!" << std::endl;
		return (1);
	}
	
	// Open input file
	std::ifstream infile(filename.c_str());
	if (!infile)
	{
		std::cerr << "Error: could not open input file." << std::endl;
		return (1);
	}

	// Open output file
	std::ofstream outfile((filename + ".replace").c_str());
	if (!outfile)
	{
		std::cerr << "Error: could not open/create output file." << std::endl;
		return (1);
	}

	// Read entire file into a string
	std::string line;
	while (std::getline(infile, line))
	{
		//TODO: implement search and replace for this line
		std::string new_line = replaceAll(line, s1, s2);
		outfile << new_line << std::endl;
	}
	return (0);
}
