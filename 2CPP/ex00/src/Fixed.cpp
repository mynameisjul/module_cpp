#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << GRN << "Default constructor called" << RESET << std::endl;
}

Fixed::~Fixed() {
	std::cout << RED << "Destructor called with value " << _value << RESET << std::endl;
}

Fixed::Fixed(const Fixed &other) {
	std::cout << "Copy constructor called" << std::endl;
	*this = other;
}

Fixed & Fixed::operator=(Fixed const &other) {
	std::cout << CYN << "Copy assignment operator called" << RESET << std::endl;

	if (this == &other)
		return (*this);
	
	_value = other.getRawBits();
	return (*this);
}

int Fixed::getRawBits( void ) const {
	std::cout << YEL << "getRawBits member function called" << RESET << std::endl;
	return (_value);
}

void Fixed::setRawBits( int const raw) {
	std::cout << YEL << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}
