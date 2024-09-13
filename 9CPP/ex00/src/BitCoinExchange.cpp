#include "BitCoinExchange.hpp"

// HELPERS
void	BitCoinExchange::isValidFileName(std::string name) {
	if (name.find(".") != name.rfind("."))
		throw (InvalidFileName());
	if (name.find(".csv", name.size() - 4) == std::string::npos)
		throw(InvalidFileName());
}

void	BitCoinExchange::openRefFile() {
	std::string name = "data.csv";

	ref_file.open(name.c_str());
	if (ref_file.fail())
		throw (CouldNotOpenFile());
}

bool	BitCoinExchange::isValidDate(std::string date) {
	if (date.size() != 10 || date[4] != '-' || date[7] != '-')
		return false;

	int	y = atoi(date.substr(0, 4).c_str());
	int m = atoi(date.substr(5, 2).c_str());
	int d = atoi(date.substr(8, 2).c_str());
	if (y < 2009 || y > 2024)
		return false;
	if (m < 1 || m > 12)
		return false;
	if (d < 1 || d > 31)
		return false;
	if (m == 4 || m == 6 || m == 9 || m == 11) {
		if (d > 30)
			return false;
	}
	if (m == 2) {
		if ((y == 2012 || y == 2016 || y == 2020 || y == 2024) && d > 29)
			return false;
		else if (!(y == 2012 || y == 2016 || y == 2020 || y == 2024) && d > 28)
			return false;
	}
	return true;
}

int	BitCoinExchange::isValidValue(std::string value, bool isRate) {
	char	*end;
	double	nb = strtod(value.c_str(), &end);

	if (*end != 0)
		return -1;
	if (nb >= 0) {
		if (isRate)
			return 0;
		else {
			if (nb > 1000)
				return -2;
			return 0;
		}
	}
	return -3;
}

// FILE TO MAP
void	BitCoinExchange::fileToMap() {
	std::string line;

	while (getline(ref_file, line)) {
		std::string date = line.substr(0, 10);
		std::string value = line.substr(11, line.size() - 10);
		if (isValidDate(date) && isValidValue(value, true) == 0) {
			char *end;
			double nb = strtod(value.c_str(), &end);
			if (*end == 0) 
				ref_map[date] = nb;
		}
	}
}


void	BitCoinExchange::inputToOutput(std::ifstream &inf) {
	try {
		std::string line;
		getline(inf, line);
		while (getline(inf, line)) {
			if (line.substr(10, 3) != " | ")
				std::cout << "Error: bad input => \"yyyy-mm-dd | value\"" << std::endl;
			else if (isValidDate(line.substr(0, 10)) == false)
				std::cout << "Error: bad input => " << line.substr(0, 10) << std::endl;
			else if (isValidValue(&line[13], false) != 0) {
				int validvalue = isValidValue(&line[13], false);
				if (validvalue == -1)
					std::cout << "Error: value must be a number" << std::endl;
				if (validvalue == -2)
					std::cout << "Error: too large a number" << std::endl;
				if (validvalue == -3)
					std::cout << "Error: not a positive number" << std::endl;
			}
			else {
				std::cout << line.substr(0, 10) << " => " << line.substr(13, line.size() - 13) << " = ";
				
				char *end;
				double val = strtod(&line[13], &end);

				std::map<std::string, double>::const_iterator it = ref_map.lower_bound(line.substr(0, 10));
				if (it == ref_map.begin())
					std::cerr << "Error: no input for this date" << std::endl;
				else {
					if (it->first != line.substr(0, 10))
						it--;
					std::cout << it->second * val << std::endl;
				}
			}
		}
		inf.close();
	}
	catch (std::exception &e) {
		throw(e);
	}
}

// CONSTRUCTORS AND DESTRUCTORS
BitCoinExchange::BitCoinExchange() {
	openRefFile();
	fileToMap();
}

BitCoinExchange::BitCoinExchange(BitCoinExchange const &other) {
	*this = other;
}

BitCoinExchange & BitCoinExchange::operator=(BitCoinExchange const &other) {
	if (this != &other) {
		ref_map = other.ref_map;
		openRefFile();
	}
	return *this;
}

BitCoinExchange::~BitCoinExchange() {
	ref_file.close();
}

// DEBUG HELPERS

void BitCoinExchange::printMap() {
	std::map<std::string, double>::const_iterator it;
    for (it = ref_map.begin(); it != ref_map.end(); ++it) {
        std::cout << it->first << ": " << it->second << std::endl;
    }
}