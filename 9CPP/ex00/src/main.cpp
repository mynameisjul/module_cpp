#include "BitCoinExchange.hpp"

int main(int ac, char **av) {
	if (ac != 2 || invalidFileName(av[1]))
	{
		std::cerr << "Argument format: './btc " << std::endl;
	}
}