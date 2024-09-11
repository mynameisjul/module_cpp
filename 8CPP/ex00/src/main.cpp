#include <vector>
#include <list>
#include <stdlib.h>
#include "easyfind.hpp"



const char *NotFoundException::what() const throw() {
	return "Value not found";
}

int main(int ac, char **av) {
	if (ac != 2) {
		return (2);
	}
	int n = atoi(av[1]);

	std::vector<int> intvec;
	for (int i = 1; i < 9; i++) {
		intvec.push_back(i);
	}

	std::list<int> intlist;
	for (int i = 1; i < 9; i++) {
		intlist.push_back(i);
	}

	try {
		easyfind(intvec, n);
	}
	catch (NotFoundException const &e) {
		std::cerr << e.what() << std::endl;
	}

	try {
		easyfind(intlist, n);
	}
	catch (NotFoundException const &e) {
		std::cerr << e.what() << std::endl;
	}

	return (0);
}