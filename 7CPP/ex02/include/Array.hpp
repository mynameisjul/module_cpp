#ifndef ARRAY_HPP
#define ARRAY_HPP

#include <string>
#include <iostream>

template <typename T> class Array {
	private:
		T		*_value;
		size_t	_len;
	public:
		Array();
		Array(unsigned int n);
		Array(const Array &other);
		const Array &operator=(const Array &other);
		~Array();

		T &operator[](size_t i) const;
		size_t	size() const;
		void	setter(T elmnt, size_t i);

		class OutOfBoundsException : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

#include "Array.tpp"

#endif /* ARRAY_HPP */