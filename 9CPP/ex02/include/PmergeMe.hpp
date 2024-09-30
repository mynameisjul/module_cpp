#pragma once

#include <algorithm>
#include <iterator>
#include <iostream>
#include <fstream>
#include <deque>
#include <vector>
//#include "PmergeMe.tpp"

template <typename T, typename P>
class PmergeMe {
	private:
		T				_arr;
		P				_parr;
		bool			_isVec;
		bool			_odd;
		unsigned int	_straggler;
		std::deque<unsigned int> jacobVec; 

		// HELPER FUNCTIONS
		void		initJacobVec();
		void		buildArray(char **arr);
		bool		isSorted();
		void		isOdd();
		void		sortPairs();
		void		mergePair(P &arr, int p, int q, int r);
		void		mergeSortPair(P &arr, int l, int r);
		void		binaryInsert(T &S, unsigned int n, typename T::iterator pos_pair);
		T		jacobsthalInsertionSort();
		//void	insertStraggler();
		PmergeMe() {}

	public:
		// PUBLIC TYPES
		typedef typename T::iterator Iterator;
		// DEBUG HELPER
		void	printArr(std::ostream & o) const;
		void	printPairArr(std::ostream &o) const;

		// CORE FUNCTION
		void	displaySorted(char **av);

		// CONSTRUCTORS AND DESTRUCTOR
		PmergeMe(const T &array, const P&parr, bool isVec) : _arr(array), _parr(parr), _isVec(isVec) {
			initJacobVec();
		}
		PmergeMe(const PmergeMe<T, P> &other) {
				*this = other;
		}
		PmergeMe<T, P> &operator=(const PmergeMe<T, P> &other) {
			if (this != &other) {
				_arr = other._arr;
				_parr = other._parr;
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

template <typename T, typename P>
void	PmergeMe<T, P>::initJacobVec() {
	unsigned long un = 1;
	unsigned long unn = 1;

	jacobVec.push_back(unn);
	while (unn <= 1431655765) {
		unsigned int tmp = 2 * un + unn;
		jacobVec.push_back(tmp);
		un = unn;
		unn = tmp; 
	}
}

template <typename T, typename P>
void	PmergeMe<T, P>::buildArray(char **av) {
	for (size_t i = 0; av[i]; i++) {
		unsigned int	value;

		value = strtoul(av[i], NULL, 10);
		if (std::find(_arr.begin(), _arr.end(), value) != _arr.end())
			throw (DuplicateValue());
		_arr.push_back(value);
	}
}

template <typename T, typename P>
bool	PmergeMe<T, P>::isSorted() {
	for (size_t i = 1; i < _arr.size(); i++) {
		if (_arr[i] < _arr[i - 1])
			return false;
	}
	return true;
}

template <typename T, typename P>
void	PmergeMe<T, P>::isOdd() {
	if (_arr.size() % 2 == 1) {
		_straggler = _arr.back();
		_odd = true;
		_arr.pop_back();
	}
	else
		_odd = false;
}

template <typename T, typename P> 
void	PmergeMe<T, P>::sortPairs() {
	for (size_t i = 0; i < _arr.size() - 1; i += 2) {
		if (_arr[i] > _arr[i + 1])
			_parr.push_back(std::make_pair(_arr[i + 1], _arr[i]));
		else
			_parr.push_back(std::make_pair(_arr[i], _arr[i + 1]));
	}
}

template <typename T, typename P>
void	PmergeMe<T, P>::mergePair(P &arr, int p,  int q, int r) {
	int n1 = q - p + 1;
	int n2 = r - q;

	P L;
	P M;

	std::cout << "PRINT L = ";
	for (int i = 0; i < n1; i++) {
		L.push_back(arr[p + i]);
		std::cout << L[i].first << " " << L[i].second << " | "; }
	std::cout << std::endl;
	
	std::cout << "PRINT M = ";
	for (int j = 0; j < n2; j++) {
		M.push_back(arr[q + 1 + j]);
		std::cout << M[j].first << " " << M[j].second << " | " ; }
	std::cout << std::endl;

	int i = 0, j = 0, k = p;

	while (i < n1 && j < n2) {
		if (L[i].second <= M[j].second) {
			arr[k] = L[i];
			i++;
		}
		else {
			arr[k] = M[j];
			j ++;
		}
		k ++;
	}

	while (i < n1) {
		arr[k] = L[i];
		i++;
		k++;
	}

	while (j < n2) {
		arr[k] = M[j];
		j++;
		k++;
	}
}

template <typename T, typename P>
void PmergeMe<T, P>::mergeSortPair(P &arr, int l, int r) {
	if (l >= r)
		return;

	int m = l + (r - l) / 2;

	mergeSortPair(arr, l, m);
	mergeSortPair(arr, m + 1, r);
	mergePair(arr, l, m, r);
}

template <typename T, typename P>
void PmergeMe<T, P>::binaryInsert(T &S, unsigned int n, typename T::iterator pos_pair) {
	size_t	left = 0;
	size_t	right = pos_pair - S.begin();
	
	while (left <= right) {
		size_t mid = left + right / 2;
		if (n > S[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	S.insert(S.begin() + left, n);
}

template <typename T, typename P>
T PmergeMe<T, P>::jacobsthalInsertionSort() {
	T S;

	// if (_isVec == true)
	// 	S.reserve(_arr.size() + 1);
	S.push_back(_arr[0]);
	S.push_back(_arr[1]);

	size_t pairIndex = 2;
	size_t pairIndexMax = _arr.size() / 2;
	size_t jacIndex = 1;
	while (pairIndexMax >= jacobVec[jacIndex]) 
	{
		size_t bIndex = (pairIndex * 2) - 1;
		while (bIndex <= jacobVec[jacIndex] * 2 - 1) {
			S.push_back(_arr[bIndex]);
			bIndex += 2;
		}

		size_t aIndex = (jacobVec[jacIndex] - 1) * 2;
		while (aIndex > (jacobVec[jacIndex - 1] - 1) * 2) {
			binaryInsert(S, _arr[aIndex], std::find(S.begin(), S.end(), _arr[aIndex + 1]));
			aIndex-=2;
		}
		pairIndex = jacobVec[jacIndex] + 1;
		jacIndex++;
	}

	while (pairIndex <= _arr.size() / 2) {

		size_t bIndex = (pairIndex * 2) - 1;
		while (bIndex < _arr.size()) {

			S.push_back(_arr[bIndex]);
			bIndex += 2;
		}

		size_t aIndex = (pairIndex - 1) * 2;
		while (aIndex < _arr.size()) {

			binaryInsert(S, _arr[aIndex], std::find(S.begin(), S.end(), _arr[aIndex + 1]));
			aIndex += 2;
		}
		pairIndex++;
	}
	return S;
}

// CORE FUNCTION
template <typename T, typename P>
void	PmergeMe<T, P>::displaySorted(char **av) {
	try {
		buildArray(av);
		if (isSorted()) {
			std::cout << *this << std::endl;
			std::cout << "Array already sorted - time to process = 0 us" << std::endl;
			return;
		}
		isOdd();
		sortPairs();
		std::cout << "After sort pairs yoyo = ";
		printPairArr(std::cout);
		std::cout << std::endl; // DEBUG
		std::cout << std::endl;
		mergeSortPair(_parr, 0, _parr.size() - 1);
		std::cout << "After merge sort pairs = "; 
		printPairArr(std::cout);
		std::cout << std::endl; // DEBUG
		// T new_arr = jacobsthalInsertionSort();
		// for (size_t i = 0; i < new_arr.size(); i++) {
		// 	std::cout << new_arr[i] << " ";
		// }
		// std::cout << std::endl;
	}
	catch (std::exception &e) {
		std::cerr << "Error: " << e.what() << std::endl;
		return ;
	}
}

// EXCEPTION CLASS
template <typename T, typename P>
const char 	*PmergeMe<T, P>::DuplicateValue::what() const throw() {
	return "Duplicate value detected";
}

// DEBUG HELPER
template <typename T, typename P>
void	PmergeMe<T, P>::printArr(std::ostream & o) const {
	for (size_t i = 0; i < _arr.size(); i++) {
		o << _arr[i] << " ";
		if (i % 2 == 1)
			o << "| ";
	}
}

template <typename T, typename P>
void	PmergeMe<T, P>::printPairArr(std::ostream &o) const {
	for (size_t i = 0; i < _parr.size(); i++) {
		o << _parr[i].first << " " << _parr[i].second << " | ";
	}
}

template <typename T, typename P>
std::ostream & operator<<(std::ostream & o, PmergeMe<T, P> const &i) {
	i.printArr(o);
	return o;
}