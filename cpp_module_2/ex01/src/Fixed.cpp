#include "Fixed.hpp"

Fixed::Fixed() : _value(0) {
	std::cout << BGRN << "Calling default constructor" << RESET << std::endl;
}

Fixed::Fixed(const int value) {
	std::cout << BGRN << "Calling int constructor with value " << value << RESET << std::endl;
	_value = value << _bits;
}

Fixed::Fixed(const float value) {
	std::cout << BGRN << "Calling float constructor with value " << value << RESET << std::endl;
	_value = roundf(value * (1 << _bits));
}

Fixed::Fixed(Fixed const &other) : _value(other._value) {
	std::cout << BGRN << "Calling copy constructor with value " << other << RESET << std::endl;
}

Fixed & Fixed::operator=(Fixed const &other) {
	std::cout << BGRN << "Calling copy assignment operator with value " << other << RESET << std::endl;
	
	if (this == &other)
		return (*this);
	
	_value = other.getRawBits();
	return (*this);
}

Fixed::~Fixed() {
	std::cout << BRED << "Calling destructor with value " << *this << RESET << std::endl;
}

int Fixed::getRawBits( void ) const {
	std::cout << YEL << "getRawBits member function called" << RESET << std::endl;
	return (_value);
}

void Fixed::setRawBits( int const raw) {
	std::cout << YEL << "setRawBits member function called" << RESET << std::endl;
	_value = raw;
}

float	Fixed::toFloat( void ) const {
	return ((float) _value / (1 << _bits));
}

	int		Fixed::toInt( void ) const {
		return ((int) _value >> _bits );
}

std::ostream & operator<<(std::ostream & o, Fixed const & i ) {
	o << i.toFloat(); 
	return o;
}