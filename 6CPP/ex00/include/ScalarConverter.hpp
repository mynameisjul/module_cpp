#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include "scalarconverter.h"

class ScalarConverter {
	private:
		// ========== CONSTRUCTORS AND DESTRUCTOR
		ScalarConverter();
		ScalarConverter(const ScalarConverter& other);
		~ScalarConverter();
		ScalarConverter& operator=(const ScalarConverter& other);
	public:
		static void	convert(const std::string &literal);
};

#endif /* SCALARCONVERTER_HPP */