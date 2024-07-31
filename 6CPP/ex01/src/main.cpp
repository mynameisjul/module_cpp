#include <string>
#include <iostream>
#include <fstream>
#include <stdint.h>
#include "Serializer.hpp"

int main() {

	{
		Data d = {"Age", 23};
		std::cout << "===== Data 1 =====" << std::endl;
		std::cout << "Ptr = " << &d << std::endl;
		uintptr_t raw = Serializer::serialize(&d);
		std::cout << "Serialized ptr = " << raw << std::endl;
		Data *ptr = Serializer::deserialize(raw);
		std::cout << "Deserialized ptr = " << ptr << std::endl;
	}
	
	{
		Data *d = 0;
		std::cout << "===== Data 2 =====" << std::endl;
		std::cout << "Ptr = " << d << std::endl;
		uintptr_t raw = Serializer::serialize(d);
		std::cout << "Serialized ptr = " << raw << std::endl;
		Data *ptr = Serializer::deserialize(raw);
		std::cout << "Deserialized ptr = " << ptr << std::endl;
	}

	return 0;
}