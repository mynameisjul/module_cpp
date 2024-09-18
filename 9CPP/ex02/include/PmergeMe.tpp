#pragma once

#include "PmergeMe.hpp"

// HELPER FUNCTIONS

template <typename T>
void	PmergeMe<T>::buildArray(char **av) {
	for (size_t i = 0; av[i]; i++) {
		unsigned int	value;

		value = strtoul(av[i]);
		if (_arr.find(value) != _arr.end())
			throw (DuplicateValue());
		_arr.push_back(value);
	}
}

template <typename T>
bool	PmergeMe<T>::isSorted() {
	for (size_t i = _arr.begin() + 1; i < _arr.end(); i++) {
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
	for (size_t i = 0; i < _arr.end() - 1; i += 2) {
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
		T	right(arr.begin() + mid + 1, arr.end());

		left = mergeSort(left);
		right = mergeSort(right);

		size_t i = 0;
		size_t j = 0;
		size_t k = 0;
		while (i < left.size() && j < right.size()) {
			if (left[i + 1] < right[j + 1]) {
				arr[k] = left[i];
				arr[k + 1] = left[i + 1]
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

		return arr;
	}
}

template <typename T>
void PmergeMe<T>::mergeSortPairSequence() {
	_arr = mergePairSort(_arr);
}

template <typename T>
void jacobasthalInsertionSort() {
	T S;

	if (dynamic_cast<vector*>(&_arr))
		S.reserve(_arr.size());
	for (size_t i = 1; i < _arr.end(); i += 2) {
		S.push
	}
}

// EXCEPTION CLASS
template <typename T>
const char 	*PmergeMe<T>::DuplicateValue::what() const throw() {
	return "Duplicate value detected";
}