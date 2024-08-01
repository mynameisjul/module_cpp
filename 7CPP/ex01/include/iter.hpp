#ifndef ITER_HPP
#define ITER_HPP

#include <string>
#include <iostream>

template <typename T, typename L, typename F>void iter(T *adr, L length, F f) {
	if (adr == NULL || f == NULL || length < 0)
		return ;
	for (L i = 0; i < length; i++) {
		f(adr[i]);
	}
}

#endif /* ITER_HPP */