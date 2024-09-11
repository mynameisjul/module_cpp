#pragma once

#include <stack>
#include <deque>

template <class T, class Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
	public:
		MutantStack() {};
		MutantStack(Container container) : std::stack<T, Container>(container) {};
		MutantStack(MutantStack const &other) {
			*this = other;
		};
		~MutantStack() {};
		MutantStack &operator=(const MutantStack &other) {
			if (this != &other)
				std::stack<T>::operator=(other);
			return *this;
		}
		
		typedef typename Container::iterator iterator;
		iterator begin() {return this->c.begin();};
		iterator end() {return this->c.end();};
};