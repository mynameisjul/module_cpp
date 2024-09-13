#include "BitCoinExchange.hpp"

int main(int ac, char **av) {
	BitCoinExchange btc;
	std::string	name = av[ac - 1];

	try {
		btc.openFile(name);
		return (printf("yes\n"), 0);
	}
	catch (std::exception &e) {
		return (printf("Error: %s\n", e.what()), 1);
	}
}