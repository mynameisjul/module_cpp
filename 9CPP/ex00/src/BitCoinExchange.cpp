#include "BitCoinExchange.hpp"

// HELPERS
void	BitCoinExchange::openFile(std::string name) {
	try {
		ref_file.open(name.c_str());
	}
	catch (std::exception const &e) {
		throw (CouldNotOpenFile());
	}
} 

void	BitCoinExchange::isValidFileName(std::string name) {
	if (name.find(".") != name.rfind("."))
		throw (InvalidFileName());
	if (name.find(".csv", name.size() - 4) == std::string::npos)
		throw(InvalidFileName());
} 

bool	BitCoinExchange::isValidDate(std::string date) {
	(void) date;
	return true;
} 

time_t	BitCoinExchange::stringToKey(std::string date) {
	(void) date;
	return 0;
}

bool	BitCoinExchange::isValidValue(std::string value) {
	(void) value;
	return true;
}

// FILE TO MAP
void	BitCoinExchange::fileToMap(std::string input_file) {
	(void) input_file;
}

// CONSTRUCTORS AND DESTRUCTORS
BitCoinExchange::BitCoinExchange() {
	
}

BitCoinExchange::BitCoinExchange(BitCoinExchange const &other) {
	(void) other;
}

BitCoinExchange & BitCoinExchange::operator=(BitCoinExchange const &other) {
	(void) other;
	return *this;
}

void	BitCoinExchange::inputToOutput(std::string input_file) {
	(void) input_file;
}
