#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <limits.h>
#include <limits>
#include "Base.hpp"
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base * generate(void) {
	int rand = std::rand() % 3;
	Base	*ptr = 0;

	switch (rand)
	{
	case 0:
		ptr = new A();
		break;
	
	case 1:
		ptr = new B();
		break;

	case 2:
		ptr = new C();
		break;
	}
	return ptr;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A" << std::endl;
	if (dynamic_cast<B*>(p))
		std::cout << "B" << std::endl;
	if (dynamic_cast<C*>(p))
		std::cout << "C" << std::endl;
}

void identify(Base& p) {
	try {
		A &a = dynamic_cast<A&>(p);
		(void) a;
		std::cout << "A" << std::endl;
	}
	catch (std::exception &e) {}

	try {
		B &b = dynamic_cast<B&>(p);
		(void) b;
		std::cout << "B" << std::endl;
	}
	catch (std::exception &e) {}

	try {
		C &c = dynamic_cast<C&>(p);
		(void) c;
		std::cout << "C" << std::endl;
	}
	catch (std::exception &e) {}
}

int main() {
	std::cout << "Write 'exit' to exit or anything to try the functions" << std::endl;
	std::string line = "";
	std::getline(std::cin, line);
	if (std::cin.eof())
		return (0);
	while (line != "exit") {
		Base *ptr = generate();

		identify(ptr);
		identify(*ptr);

		delete ptr;
		std::getline(std::cin, line);
		if (std::cin.eof())
			return (0);
	}
	return (0);
}