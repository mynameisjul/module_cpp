#include <string>
#include <iostream>
#include "Array.hpp"

int main() {
	Array<std::string>	strings(5);
	Array<float>		floats(3);
	Array<int>			ints(8);
	Array<int>			ints_cpy(ints);

	std::cout << "Testing the use of [] in and out of bounds" << std::endl;
	try {
		std::cout << "strings[4] = " << strings[4] << std::endl;
	}
	catch (std::exception const &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	try {
		std::cout << "strings[9] = " << strings[9] << std::endl;
	}
	catch (std::exception const &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	std::cout << "==========" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Testing the same with floats" << std::endl;
	try {
		std::cout << "floats[1] = " << floats[1] << std::endl;
	}
	catch (std::exception const &e) {
			std::cout << "Error: " << e.what() << std::endl;
		}
	try {
		std::cout << "floats[9] = " << floats[9] << std::endl;
	}
	catch (std::exception const &e) {
		std::cout << "Error: " << e.what() << std::endl;
	}
	std::cout << "==========" << std::endl;
	std::cout << "" << std::endl;

	std::cout << "Testing that the copies are deep" << std::endl;
	std::cout << "Setting ints[0] to 4" << std::endl;
	ints.setter(4, 0);
	std::cout << "ints[0] = " << ints[0] << std::endl;
	std::cout << "ints_cpy[0] = " << ints_cpy[0] << std::endl;
	std::cout << "==========" << std::endl;
	std::cout << "" << std::endl;

	return 0;
}
