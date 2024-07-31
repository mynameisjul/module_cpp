#ifndef SERIALIZER_HPP
#define SERIALIZER_HPP

#include <string>
#include <stdint.h>

typedef struct {
	std::string name;
	int			value;
} Data;

class Serializer {
	private:
		Serializer();
		~Serializer();
	public:
		static uintptr_t serialize(Data *ptr);
		static Data* deserialize(uintptr_t raw);
};

#endif /* SERIALIZER_HPP */