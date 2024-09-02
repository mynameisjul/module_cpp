#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <iostream>

class Span {
	private:
		size_t				_N;
		std::vector<int>	_arr;
	public:
		// CONSTRUCTORS DESTRUCTOR
		Span(size_t N);
		Span(const Span &other);
		~Span();
		Span &operator=(const Span &other);

		// GETTERS AND SETTERS
		void	fill();
		void	addNumber(int n);
		size_t	getSize() const;
		int		getElement(size_t i) const;

		// SPECIFIC MEMBERS
		size_t	shortestSpan();
		size_t	longestSpan() const;

		// EXCEPTION CLASS
		class ArrayFull : std::exception {
			public:
				virtual const char *what() const throw();
		};
		class NoSpanFound : std::exception {
			public:
				virtual const char *what() const throw();
		};
		class OutOfBound : std::exception {
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream & o, Span const & s);

#endif /* SPAN_HPP */