#include "scalarconverter.h"

void printType() 
{
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: impossible" << std::endl;
	std::cout << "double: impossible" << std::endl;
}

void printType(const std::string &literal) {
	std::cout << "char: impossible" << std::endl;
	std::cout << "int: impossible" << std::endl;
	std::cout << "float: ";
	if (literal == "-inf" || literal == "-inff")
		std::cout << "-inff" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "+inff" << std::endl;
	else
		std::cout << "nanf" << std::endl;
	std::cout << "double: ";
	if (literal == "-inf" || literal == "-inff")
		std::cout << "-inf" << std::endl;
	else if (literal == "+inf" || literal == "+inff")
		std::cout << "+inf" << std::endl;
	else
		std::cout << "nan" << std::endl;
}

void printType(char c) 
{
	int n = (int) c;

	std::cout << "char: " <<  c << std::endl;
	std::cout << "int: " << n << std::endl;
	std::cout << "float: " << n << ".0f" << std::endl;
	std::cout << "double: " << n << ".0" << std::endl;
}

void printType(int i)
{
	if (i < std::numeric_limits<char>::min() || i > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(i))
		std::cout << "char: " <<  (char) i << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << i << ".0f" << std::endl;
	std::cout << "double: " << i << ".0" << std::endl;
}

void printType(float f)
{
	// CHAR
	if (f < std::numeric_limits<char>::min() || f > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(f))
		std::cout << "char: " <<  (char) f << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// INT
	if (f < std::numeric_limits<int>::min() || f > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << (int) f << std::endl;

	// FLOAT
	if (f - (int) f == 0 && f < 1000000)
		std::cout << "float: " << f << ".0f" << std::endl;
	else
		std::cout << "float: " << f << "f" << std::endl;

	// DOUBLE
	if (f - (int) f == 0 && f < 1000000)
		std::cout << "double: " << (double) f << ".0" << std::endl;
	else
		std::cout << "double: " << (double) f << std::endl;
}

void printType(double d)
{
	// CHAR
	if (d < std::numeric_limits<char>::min() || d > std::numeric_limits<char>::max())
		std::cout << "char: impossible" << std::endl;
	else if (isprint(d))
		std::cout << "char: " <<  (char) d << std::endl;
	else
		std::cout << "char: Non displayable" << std::endl;

	// INT
	if (d < std::numeric_limits<int>::min() || d > std::numeric_limits<int>::max())
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << (int) d << std::endl;

	// FLOAT
	if (d < std::numeric_limits<float>::min() || d > std::numeric_limits<float>::max())
		std::cout << "float: impossible" << std::endl;
	else {
		float f = d;
		if (f - (int) f == 0 && f < 1000000)
			std::cout << "float: " << f << ".0f" << std::endl;
		else
			std::cout << "float: " << f << "f" << std::endl;
	}

	// DOUBLE
	if (d - (int) d == 0 && d < 1000000)
		std::cout << "double: " << d << ".0" << std::endl;
	else
		std::cout << "double: " << d << std::endl;
}
