#ifndef ARRAY_TPP
#define ARRAY_TPP

#include <string>
#include <iostream>
#include "Array.hpp"

template <typename T>
Array<T>::Array() : _value(new T[0]), _len(0) {
	std::cout << "Calling default constructor" << std::endl;
}

template <typename T>
Array<T>::Array(unsigned int n) : _value(new T[n]), _len(n) {
	std::cout << "Calling parameterized constructor" << std::endl;
	for (size_t i = 0; i < n; i++) {
		_value[i] = T();
	}
}

template <typename T>
const Array<T>& Array<T>::operator=(const Array &other) {
	if (this != &other) {
		_len = other._len;
		if (_value) {
			delete [] _value;
		}
		_value = new T[_len];
		for (size_t i = 0; i < _len; i++) {
			_value[i] = other._value[i];
		}
	}
	return *this;
}

template <typename T>
Array<T>::Array(const Array &other) : _value(new T[other._len]), _len(other._len) {
	std::cout << "Calling copy constructor" << std::endl;
	for (size_t i = 0; i < _len; i++) {
		_value[i] = other._value[i];
	}
}

template <typename T>
Array<T>::~Array() {
	std::cout << "Calling destructor" << std::endl;
	delete [] _value;
}

template <typename T>
T & Array<T>::operator[](size_t i) const {
	if (i >= _len) {
		throw OutOfBoundsException();
	}
	return _value[i];
}

template <typename T>
size_t Array<T>::size() const {
	return _len;
}

template <typename T>
void Array<T>::setter(T elmnt, size_t i) {
	if (i >= _len)
		throw OutOfBoundsException();
	else  {
		_value[i] = elmnt;
	}
}

template <typename T>
const char* Array<T>::OutOfBoundsException::what() const throw() {
	return "Value is out of bounds";
}

#endif /* ARRAY_TPP */