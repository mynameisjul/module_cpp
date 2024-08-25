#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <string>
#include <iostream>
#include "Array.hpp"

template <typename T> Array<T>::Array() : _value(new T[0]), _len(0) {
	std::cout << "Calling default constructor" << std::endl;
}

template <typename T> Array<T>::Array(unsigned int n) : _value(new T[n]), _len(n) {
	std::cout << "Calling parameterized constructor" << std::endl;
	for (int i = 0; i < n; i++) {
		_value[i] = 0;
	}
}

template <typename T> Array<T>::Array &operator=(const Array &other) {
	
}

template <typename T> Array<T>::Array(const Array &other)
		T &operator[](size_t i) const;
		size_t size() const;

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw();
		}

#endif /* ARRAY_TPP */