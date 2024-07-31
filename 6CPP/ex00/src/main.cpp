#include "scalarconverter.h"

int main() {
	std::string literal = "";

	std::cout << "Enter any literal or 'EXIT' to exit" << std::endl;
	while (literal != "EXIT") {
		
		std::getline(std::cin, literal);
		if (std::cin.eof())
			return (0);
		ScalarConverter::convert(literal);
	}
	return 0;
}