#include <ctime>
#include <sys/time.h>
#include <list>
#include "PmergeMe.hpp"

bool isValidArray(char **av) {
	for (size_t i = 0; av[i]; i++) {
		unsigned int	value;
		char			*end;

		value = strtoul(av[i], &end, 10);

		if (errno == ERANGE || value > 4294967295) {
			return false;
		}

		if (*end != 0) {
			return false;
		}
	}
	return true;
}

int main(int ac, char **av) {
	if (ac < 2) {
		std::cerr << "Enter at least one number" << std::endl;
		return 1;
	}

	if (isValidArray(&av[1]) == false) {
		std::cerr << "One or more argument is not an unsigned int" << std::endl;
		return 1;
	}

	std::vector<unsigned int> vec;
	std::vector<std::pair<unsigned int, unsigned int> > pvec;
	std::deque<unsigned int> deq;
	std::deque<std::pair<unsigned int, unsigned int> > pdeq;
	std::list<unsigned int> lst;
	std::list<std::pair<unsigned int, unsigned int> > plst;

	vec.reserve(ac - 1);
	pvec.reserve((ac - 1) / 2);

	{	// VECTOR
		try {
			PmergeMe<std::vector<unsigned int>, std::vector<std::pair<unsigned int, unsigned int> > >	pm(vec, pvec, true);
			std::cout << "WITH VECTOR" << std::endl;
			pm.displaySorted(ac - 1, &av[1]);
			std::cout << "___________________" << std::endl;

		}
		catch (std::exception &e) {
			std::cerr << "Error: " << e.what() << std::endl;
			return 1;
		}
	}

	{	// DEQUE
		try {
			PmergeMe<std::deque<unsigned int>, std::deque<std::pair<unsigned int, unsigned int> > >	pm(deq, pdeq, false);
			std::cout << "WITH DEQUE" << std::endl;1 2 + 3 /
	// 	try {
	// 		PmergeMe<std::list<unsigned int>, std::list<std::pair<unsigned int, unsigned int> > >	pm(lst, plst, false);
	// 		std::cout << "WITH LIST" << std::endl;
	// 		pm.displaySorted(ac - 1, &av[1]);
	// 		std::cout << "___________________" << std::endl;

	// 	}
	// 	catch (std::exception &e) {
	// 		std::cerr << "Error: " << e.what() << std::endl;
	// 		return 1;
	// 	}
	// }
}