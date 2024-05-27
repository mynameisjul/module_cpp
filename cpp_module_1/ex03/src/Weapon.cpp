#include "Weapon.h"

const std::string&	Weapon::getType() const {
	return (_type);
}

void Weapon::setType(std::string type) {
	_type = type;
	std::cout << BGRN << "Weapon type is now: " << _type << RESET << std::endl;
}

Weapon::Weapon() : _type("Random weapon") {}
Weapon::Weapon(std::string type) : _type(type) {}
Weapon::~Weapon() {
	std::cout << RED << "Destroying the " << _type << RESET << std::endl;
}
