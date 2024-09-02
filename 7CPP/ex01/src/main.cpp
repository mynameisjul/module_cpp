#include "iter.hpp"

void print(int i) {
	std::cout << i << std::endl;
}

void print(double d) {
	std::cout << d << std::endl;
}

void print(char c) {
	std::cout << c << std::endl;
}

int main() {
	std::string msg = "Wesh!";
	const char *str = msg.c_str();
	int		arr[5] = {1, 2, 4, -3, 8};
	double	darr[5] = {3.0, 8.7, -573.8, 0.0, 7.852};
	size_t	len = 5;

	std::cout << "ITER ON A CHAR*" << std::endl;
	iter(str, len, &print);
	std::cout << std::endl;

	std::cout << "ITER ON INT ARRAY" << std::endl;
	iter(arr, len, &print);

	std::cout << "ITER WITH ON DOUBLE ARRAY" << std::endl;
	iter(darr, len, &print);
}