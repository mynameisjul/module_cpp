#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <deque>
#include <vector>
#include "PmergeMe.tpp"

template <typename T>
class PmergeMe {
	private:
		bool			_odd;
		unsigned int	_straggler;
		T				_arr;
		const std::vector<unsigned int> jacobVec = {0, 1, 1, 3, 5, 11, 21, 43, 85, 171, 341, 683, 1365, 2731, 5461, 10923, 21845, 43691, 87381, 174763, 349525, 699051, 1398101, 2796203, 5592405, 11184811, 22369621, 44739243, 89478485, 178956971, 357913941, 715827883, 1431655765, 2863311531, 4294967291};

		// HELPER FUNCTIONS
		void	buildArray(char **arr);
		bool	isSorted();
		void	isOdd();
		void	sortPairs();
		T		subArr(T arr, size_t beg, size_t end);
		T		mergePairSort(T arr);
		void	mergeSortPairSequence();
		void	jacobasthalInsertionSort();
		void	insertStraggler();

	public:
		// CORE FUNCTION
		void	displaySorted();

		// CONSTRUCTORS AND DESTRUCTOR
		PmergeMe() {}
		PmergeMe(T array) : _arr(array) {}
		PmergeMe(PmergeMe const &other) {
				*this = other;
		}
		PmergeMe &operator=(PmergeMe const &other) {
			if (this != &other) {
				_arr = other._arr;
				_odd = other._odd;
				_straggler = other._straggler;
			}
			return *this;
		}
		~PmergeMe() {}

		// EXCEPTION CLASS
		class DuplicateValue : public std::exception {
			public:
				virtual const char *what() const throw();
		};
};