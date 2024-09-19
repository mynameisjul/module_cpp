#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
//#include "PmergeMe.tpp"

template <typename T>
class PmergeMe {
	private:
		bool			_isVec;
		bool			_odd;
		unsigned int	_straggler;
		T				_arr;
		std::deque<unsigned int> jacobVec; 

		// HELPER FUNCTIONS
		void	initJacobVec();
		void	buildArray(char **arr);
		bool	isSorted();
		void	isOdd();
		void	sortPairs();
		T		mergePairSort(T arr);
		void	mergeSortPairSequence();
		void	binaryInsert(T &S, size_t i);
		void	jacobsthalInsertionSort();
		//void	insertStraggler();
		PmergeMe() {}

	public:
		// DEBUG HELPER
		void	printArr(std::ostream & o) const;

		// CORE FUNCTION
		void	displaySorted(char **av);

		// CONSTRUCTORS AND DESTRUCTOR
		PmergeMe(const T &array, bool isVec) : _arr(array), _isVec(isVec) {
			initJacobVec();
		}
		PmergeMe(const PmergeMe<T> &other) {
				*this = other;
		}
		PmergeMe<T> &operator=(const PmergeMe<T> &other) {
			if (this != &other) {
				_arr = other._arr;
				_odd = other._odd;
				_straggler = other._straggler;
				_isVec = other._isVec;
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

// HELPER FUNCTIONS

template <typename T>
void	PmergeMe<T>::initJacobVec() {
	unsigned long un = 0;
	unsigned long unn = 1;

	jacobVec.push_back(un);
	jacobVec.push_back(unn);
	while (unn <= 1431655765) {
		unsigned int tmp = 2 * un + unn;
		jacobVec.push_back(tmp);
		un = unn;
		unn = tmp; 
	}
}

template <typename T>
void	PmergeMe<T>::buildArray(char **av) {
	for (size_t i = 0; av[i]; i++) {
		unsigned int	value;

		value = strtoul(av[i], NULL, 10);
		if (std::find(_arr.begin(), _arr.end(), value) != _arr.end())
			throw (DuplicateValue());
		_arr.push_back(value);
	}
}

template <typename T>
bool	PmergeMe<T>::isSorted() {
	for (size_t i = 1; i < _arr.size(); i++) {
		if (_arr[i] < _arr[i - 1])
			return false;
	}
	return true;
}

template <typename T>
void	PmergeMe<T>::isOdd() {
	if (_arr.size() % 2 == 1) {
		_straggler = _arr.back();
		_odd = true;
		_arr.pop_back();
	}
	else
		_odd = false;
}

template <typename T> 
void	PmergeMe<T>::sortPairs() {
	for (size_t i = 0; i < _arr.size() - 1; i += 2) {
		if (_arr[i] > _arr[i + 1]) {
			unsigned int tmp = _arr[i];
			_arr[i] = _arr[i + 1];
			_arr[i + 1] = tmp;
		}
	}
}

template <typename T>
T	PmergeMe<T>::mergePairSort(T arr) {
	if (arr.size() > 2) {
		int mid = arr.size() / 2;
		T	left(arr.begin(), arr.begin() + mid);
		T	right(arr.begin() + mid, arr.end());

		left = mergePairSort(left);
		right = mergePairSort(right);

		size_t i = 0;
		size_t j = 0;
		size_t k = 0;
		while (i < left.size() && j < right.size()) {
			if (left[i + 1] < right[j + 1]) {
				arr[k] = left[i];
				arr[k + 1] = left[i + 1];
				i += 2;
			}
			else {
				arr[k] = right[j];
				arr[k + 1] = right[j + 1];
				j += 2;
			}
			k += 2;
		}

		while (i < left.size()) {
			arr[k] = left[i];
			k++;
			i++;
		}

		while (j < right.size()) {
			arr[k] = right[j];
			k++;
			j++;
		}
	}
	return arr;
}

template <typename T>
void PmergeMe<T>::mergeSortPairSequence() {
	_arr = mergePairSort(_arr);
}

template <typename T>
void PmergeMe<T>::binaryInsert(T &S, size_t i) {
	
}

template <typename T>
void PmergeMe<T>::jacobsthalInsertionSort() {
T S;
unsigned int jacobIndex = 3;

if (isVec)
	S.reserve(_arr.size() + 1);
S.push_back(_arr[0])
for (size_t i = 1; i < _arr.size(); i += 2) {
	S.push_back(_arr[i]);
	}

}

// CORE FUNCTION
template <typename T>
void	PmergeMe<T>::displaySorted(char **av) {
	try {
		buildArray(av);
		if (isSorted()) {
			std::cout << *this << std::endl;
			std::cout << "Array already sorted - time to process = 0 us" << std::endl;
			return;
		}
		isOdd();
		sortPairs();
		std::cout << "After sort pairs = " << *this << std::endl; // DEBUG
		mergeSortPairSequence();
		std::cout << "After merge sort pairs = " << *this << std::endl; // DEBUG
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}
}

// EXCEPTION CLASS
template <typename T>
const char 	*PmergeMe<T>::DuplicateValue::what() const throw() {
	return "Duplicate value detected";
}

// DEBUG HELPER
template <typename T>
void	PmergeMe<T>::printArr(std::ostream & o) const {
	for (size_t i = 0; i < _arr.size(); i++) {
		o << _arr[i] << " ";
	}
}

template <typename T>
std::ostream & operator<<(std::ostream & o, PmergeMe<T> const &i) {
	i.printArr(o);
	return o;
}