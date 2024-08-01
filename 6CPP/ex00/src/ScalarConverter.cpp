#include "scalarconverter.h"

// ========== UTILS
static void	isChar(const std::string &literal) {
	if (literal.size() == 1 && isprint(literal[0]) && !isdigit(literal[0])) {
		char c = (char) literal[0];
		printType(c);
		return ;
	}
}

static void isInt(const std::string &literal) {
	if (literal.size() == 0)
		return ;
	for (int i = literal[0] == '-' ? 1 : 0; i < (int) literal.size(); i++) {
		if (!isdigit(literal[i]))
			return ;
	}

	char *end;
	long l = strtol(literal.c_str(), &end, 10);
	if (*end != 0)
		return ;
	if (l > INT_MAX || l < INT_MIN)
		return (printType());
	int i = (int) l;
	printType(i);
	return ;
}

static void	isFloat(const std::string &literal) {
	if (literal.find('.') == std::string::npos)
		return ;
	if (literal.find('f') == std::string::npos)
		return ;
	
	char *end;
	float f = strtof(literal.c_str(), &end);
	if (*end != 'f' || *(end + 1) != 0)
		return ;
	if (errno == ERANGE)
		return (printType());
	printType(f);
}

static void	isDouble(const std::string &literal) {
	if (literal.find('.') == std::string::npos || literal.find('f') != std::string::npos)
		return ;
	
	char *end;
	double d = strtod(literal.c_str(), &end);
	if (*end != 0)
		return ;
	if (errno == ERANGE)
		return printType();
	printType(d);
}

static void isPseudo(const std::string &literal) {
	if (literal == "+inf" || literal == "-inf" || literal == "+inff" || literal == "-inff" || literal == "nan" || literal == "nanf")
		printType(literal);
}

// ========== CONVERTER
void	ScalarConverter::convert(const std::string &literal) {
	isChar(literal);
	isInt(literal);
	isDouble(literal);
	isFloat(literal);
	isPseudo(literal);
}

// ========== CONSTRUCTORS AND DESTRUCTOR
ScalarConverter::ScalarConverter() {
	std::cout << BGRN << "[ScalarConverter] " << RESET << "Constructor called" << std::endl;
}
ScalarConverter::ScalarConverter(const ScalarConverter& other) {
	std::cout << BGRN << "[ScalarConverter] " << RESET << "Copy constructor called" << std::endl;
	*this = other;
}
ScalarConverter::~ScalarConverter() {
	std::cout << BRED << "[ScalarConverter] " << RESET << "Default destructor called" << std::endl;
}
ScalarConverter& ScalarConverter::operator=(const ScalarConverter& other) {
	std::cout << GRN << "[ScalarConverter] " << RESET << "Copy assignment operator called" << std::endl;
	if (this != &other) {
		*this = other;
	}
	return *this;
}
