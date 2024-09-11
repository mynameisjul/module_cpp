#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>


class NotFoundException : public std::exception {
	public:
		virtual const char *what() const throw();
};

template <typename T>
void easyfind(T &container, int n) {
	if (std::find(container.begin(), container.end(), n) == container.end()) {
		throw NotFoundException();
	}
	else {
		std::cout << "Value found" << std::endl;
	}
}

#endif /* EASYFIND_HPP */