#include <string>
#include <iostream>
#include "whatever.hpp"

int main() 
{
	{
		std::cout << "==========" << std::endl;
		std::cout << "Strings: " << std::endl;
		std::string sa = "Hello";
		std::string sb = "World";
		std::cout << "sa = " << sa << std::endl;
		std::cout << "sb = " << sb << std::endl;
		std::cout << "---- Swap" << std::endl;
		::swap(sa, sb);
		std::cout << "sa = " << sa << std::endl;
		std::cout << "sb = " << sb << std::endl;
		std::cout << "---- Min" << std::endl;
		std::cout << ::min(sa, sb) << std::endl;
		std::cout << "---- Max" << std::endl;
		std::cout << ::max(sa, sb) << std::endl;
		std::cout << "==========" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "==========" << std::endl;
		std::cout << "Ints: " << std::endl;
		int a = 8;
		int b = 15;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "---- Swap" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "---- Min" << std::endl;
		std::cout << ::min(a, b) << std::endl;
		std::cout << "---- Max" << std::endl;
		std::cout << ::max(a, b) << std::endl;
		std::cout << "==========" << std::endl;
	}
	std::cout << std::endl;
	{
		std::cout << "==========" << std::endl;
		std::cout << "Floats: " << std::endl;
		float a = 8.9446;
		float b = -45.8;
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "---- Swap" << std::endl;
		::swap(a, b);
		std::cout << "a = " << a << std::endl;
		std::cout << "b = " << b << std::endl;
		std::cout << "---- Min" << std::endl;
		std::cout << ::min(a, b) << std::endl;
		std::cout << "---- Max" << std::endl;
		std::cout << ::max(a, b) << std::endl;
		std::cout << "==========" << std::endl;
	}
}