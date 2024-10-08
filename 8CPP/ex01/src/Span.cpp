#include <algorithm>
#include <cstdlib>
#include "Span.hpp"

int	custom_rand() {
	int a = std::rand();
	int b = std::rand();

	if (a % 2 == 0)
		return (b % 1000);
	else 
		return (-b % 1000);
}

// CONSTRUCTORS DESTRUCTOR
Span::Span(size_t N) : _N(N) {
	std::cout << "Calling constructor" << std::endl;
	try {
		_arr.reserve(N); 
	}
	catch (std::exception const &) {
		throw InvalidSize();
	}
}

Span::Span(const Span &other) : _N(other._N) {
	std::cout << "Calling copy constructor" << std::endl;
	_arr = other._arr;
}

Span::~Span() {
	std::cout << "Calling destructor" << std::endl;
}

Span & Span::operator=(const Span &other) {
	if (this != &other) {
		_N = other._N;
		_arr.resize(_N);
		for (size_t i = 0; i < _arr.size(); i++) {
			_arr[i] = other._arr[i];
		}
	}
	return *this;
}

// GETTERS AND SETTERS
void	Span::fill() {
	if (_N < 1)
		throw InvalidSize();
	_arr.resize(_N);
	std::srand(time(0));
    std::generate(_arr.begin(), _arr.end(), custom_rand);
}

void	Span::addNumber(int n) {
	if (_arr.size() == _N) {
		throw ArrayFull();
	}
	else {
		_arr.push_back(n);
	}
};

size_t Span::getSize() const {
	return (_N);
}

int	Span::getElement(size_t i) const {
	if (i > _arr.size())
		throw OutOfBound();
	return _arr[i];
}

// SPECIFIC MEMBERS
size_t	Span::shortestSpan() {
	if (_N < 1 || _arr.size() < 2)
		throw NoSpanFound();
	std::sort(_arr.begin(), _arr.end());
	size_t shortestSpan = 4294967296;
	for (size_t i = 0; i < _arr.size() - 1; i++) {
		if ((size_t) abs(_arr[i] - _arr[i + 1]) < shortestSpan)
			shortestSpan = (size_t) abs(_arr[i] - _arr[i + 1]); 
	}
	return shortestSpan;
}

size_t	Span::longestSpan() const {
	if (_N < 1 || _arr.size() < 2)
		throw NoSpanFound();
	
	int min = *std::min_element(_arr.begin(), _arr.end());
	int max = *std::max_element(_arr.begin(), _arr.end());
	size_t longestSpan = (size_t) max - min;
	return longestSpan;
}

// EXCEPTION CLASS
const char *Span::ArrayFull::what() const throw() {
	return "Array is full: could not add element";
}

const char *Span::NoSpanFound::what() const throw() {
	return "Array has one or less element: could not find span";
}

const char *Span::OutOfBound::what() const throw() {
	return "Could not access element: index is out of bound";
}

const char *Span::InvalidSize::what() const throw() {
	return "Size is invalid";
}

std::ostream &operator<<(std::ostream & o, Span const &s) {
	if (s.getSize() < 1)
		return o;
	o << "{";
	for (size_t i = 0; i < s.getSize(); i++) {
		o << s.getElement(i);
		if (i != s.getSize() - 1)
			o << ", ";
	}
	o << "}";
	return o;
}