#include "Weapon.h"

HumanB::HumanB(std::string name) : _name(name), _weapon(NULL) {
	std::cout << BGRN << "Creating human B named " << name << RESET << std::endl;

}

HumanB::~HumanB() {
	std::cout << BRED << "Destroying " << _name << RESET << std::endl;
}

void HumanB::attack() {
	if (_weapon)
		std::cout << BYEL << _name << " attacks with their " << _weapon->getType() << RESET << std::endl;
	else
		std::cout << BRED << "Attack is not possible: " << _name << " has no weapon" << RESET << std::endl;
}

void HumanB::setWeapon(Weapon &weapon) {
	_weapon = &weapon;
	std::cout << BGRN << _name << "'s weapon has been set to: " << _weapon->getType() << RESET << std::endl;
}
