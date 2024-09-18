#include "PmergeMe.hpp"

bool isValidArray(char **av) {
	for (size_t i = 0; av[i]; i++) {
		unsigned int	value;
		char			*end;

		value = strtoul(av[i], &end, 10);

		if (errno == ERANGE || value > UINT32_MAX) {
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
	std::deque<unsigned int> deq;

	vec.reserve(ac - 1);

	{	// VECTOR
		try {
			PmergeMe(vec);
		}
	}

	{	// DEQUE

	}
}