#include "Weapon.h"

HumanA::HumanA(std::string name, Weapon &weapon) : _name(name), _weapon(weapon) {
	std::cout << BGRN << "Creating human A named " << name << " with weapon " << weapon.getType() << RESET << std::endl;
}

HumanA::~HumanA() {
	std::cout << BRED << "Destroying " << _name << RESET << std::endl;
}

void HumanA::attack() {
	std::cout << BYEL << _name << " attacks with their " << _weapon.getType() << RESET << std::endl;
}

