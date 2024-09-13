#include "BitCoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2) {
		std::cout << "Really babe? Are you even trying?" << std::endl;
		return (EXIT_FAILURE);
	}
	try {
		BitCoinExchange btc;
		
		std::ifstream inf;

		inf.open(av[ac -1]);
		if (inf.fail())
			throw (BitCoinExchange::CouldNotOpenFile());

		try {
			btc.inputToOutput(inf);
		}
		catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
		}
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return (EXIT_SUCCESS);
}