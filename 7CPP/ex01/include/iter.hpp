#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T>
void iter(T *adr, size_t len, void (*f)(T)) {
	if (adr == NULL || f == NULL || len < 0)
		return ;
	for (size_t i = 0; i < len; i++) {
		f(adr[i]);
	}
}

#endif /* ITER_HPP */