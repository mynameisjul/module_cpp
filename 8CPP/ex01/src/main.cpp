#include <stdlib.h>
#include "Span.hpp"

int main(int ac, char **av) {
	if (ac != 2)
		return (1);

	try {
		Span vec1(atoi(av[1]));
		vec1.fill();
		std::cout << vec1 << std::endl;
		std::cout << "Longest span is: " << vec1.longestSpan() << std::endl;
		std::cout << "Shortest span is: " << vec1.shortestSpan() << std::endl;
		std::cout << "Add number to full array:" << std::endl;
		try {
			vec1.addNumber(42);
		}
		catch (Span::ArrayFull const &e) {
			std::cerr << e.what() << std::endl;
		}
	}
	catch (std::exception const &e) {
		std::cerr << e.what()  << std::endl;
	}
		return (0);
}