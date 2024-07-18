#include "sed.hpp"

int main(int ac, char **av) {
	if (ac != 4)
		std::cerr << BRED << "Wrong number of arguments." << RESET << std::endl;

	std::string search("");
	std::string replace("");

	search = av[2];
	replace = av[3];

	size_t		search_len = search.size();
	size_t		replace_len = replace.size();

	Sed sed(search, replace, search_len, replace_len);

	if (sed.sed(av[1]) == false)
		std::cout << BRED << "Error" << RESET << std::endl;
	return (0);
}
