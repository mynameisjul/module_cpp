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
	int		ilen = 5;

	std::cout << "ITER ON A CHAR* WITH INT LEN" << std::endl;
	iter(str, len, &print);
	std::cout << std::endl;

	std::cout << "ITER WITH ADDONE ON INT ARRAY" << std::endl;
	std::cout << "Before: ";
	for (int i = 0; i < ilen; i++)
		std::cout << arr[i];
	std::cout << std::endl;
	iter(&arr, ilen, &print);
	std::cout << "After: ";
	for (int i = 0; i < ilen; i++)
		std::cout << arr[i];
	std::cout << std::endl;
	std::cout << std::endl;

	std::cout << "ITER WITH PRINTDOUBLE ON DOUBLE ARRAY" << std::endl;
	iter(darr, len, &print);
}