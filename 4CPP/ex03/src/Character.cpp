#include "interface.h"

// Member functions
std::string const & Character::getName() const {
	return (_name);
}

void Character::equip(AMateria* m) {
	int i = 0;

	while (i < 4 && _inventory[i] != 0)
		i++;
	if (i == 4) {
		std::cout << RED << "[Character] Could not equip materia: inventory is full" << RESET << std::endl;
		return ;
	}
	else {
		std::cout << "[Character] Equipped materia in slot " << i << std::endl;
		_inventory[i] = m;
	}
}

void Character::unequip(int idx) {
	if (_inventory[idx]) {
		std::cout << "[Character] Dropping materia of index " << idx << " on the floor" << std::endl;
		_inventory[idx] = 0;
	}
}

void Character::use(int idx, ICharacter& target) {
	if (!_inventory[idx])
		std::cout << RED << "[Character] No materia available" << RESET << std::endl;
	else
		_inventory[idx]->use(target);
}

// Constructors and destructor
Character::Character() : _name("Default") {
	std::cout << BGRN << "[Character] Creating default character" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(std::string name) : _name(name) {
	std::cout << BGRN << "[Character] Creating character named " << name << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(Character const &other) {
	std::cout << BGRN << "[Character] Calling copy constructor" << RESET << std::endl;
	*this = other;
}

Character & Character::operator=(Character const &other) {
	std::cout << GRN << "[Character] Calling copy assignment operator" << RESET << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++)
		{
			if (_inventory[i])
				delete _inventory[i];
			if (other._inventory[i])
				_inventory[i] = other._inventory[i]->clone();
		}
	}
	return (*this);
}

Character::~Character() {
	std::cout << BRED << "[Character] Calling destructor" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
	{
		if (_inventory[i])
			delete _inventory[i];
	}
}