#include "ClapTrap.hpp"

// ========== CONSTRUCTOR AND DESTRUCTORS
ClapTrap::ClapTrap() : _name("default"), _hit_points(100), _energy_points(50),_attack_damage(20) {
	std::cout << BGRN << "Creating random ClapTrap..." << RESET << std::endl;
}

ClapTrap::ClapTrap(std::string name) : _name(name), _hit_points(100), _energy_points(50),_attack_damage(20) {
	std::cout << BGRN << "Creating ClapTrap named " << _name << "..." << RESET << std::endl;
}

ClapTrap::ClapTrap(ClapTrap const &other) {
	std::cout << BGRN << "Calling copy constructor for ClapTrap named " << other._name << "..." << RESET << std::endl;
	*this = other;
}

ClapTrap & ClapTrap::operator=(ClapTrap const &other) {
	std::cout << BGRN << "Calling copy assignment operator with name " << other._name << RESET << std::endl;
	if (this == &other)
		return (*this);
	_name = other._name;
	_energy_points = other._energy_points;
	_attack_damage = other._attack_damage;
	_hit_points = other._hit_points;
	return (*this);
}

ClapTrap::~ClapTrap() {
	std::cout << BRED << "Destroying ClapTrap named " << _name << "..." << RESET << std::endl;
}

// ========== GETTER FUNCTIONS

unsigned int ClapTrap::getHitPoints() {
	return (_hit_points);
}

unsigned int ClapTrap::getEnergyPoints() {
	return (_energy_points);
}

// ========== PUBLIC MEMBER FUNCTIONS
void ClapTrap::attack(const std::string& target) {
	if (_energy_points < 1) {
		std::cout << RED << "No energy left to attack." << RESET << std::endl;
		return ;
	}
	if (_hit_points == 0) {
		std::cout << RED << "No hit points left to attack." << RESET << std::endl;
		return ;
	}
	_energy_points--;
	std::cout << YEL << _name << " is attacking " << target << RESET << std::endl;
	std::cout << YEL << target << " loses " << _attack_damage << " hit points" << RESET << std::endl;
}


void ClapTrap::takeDamage(unsigned int amount) {
	if (_hit_points < amount) {
		std::cout << RED << _name << " took " << _hit_points << " damage and now they ded" << RESET << std::endl;
		_hit_points = 0;
	}
	else
	{
		_hit_points -= amount;
		std::cout << RED << _name << " took " << amount << " damage and it hurts :'(" << RESET << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount) {
	if (_energy_points == 0) {
		std::cout << RED << "No energy left to heal." << RESET << std::endl;
		return ;
	}
	_energy_points--;
	if (UINT32_MAX - _hit_points < amount) {
		_hit_points = UINT32_MAX;
		std::cout << GRN << _name << " hit points are at an all-time max!" << RESET << std::endl;
		return ;
	}
	_hit_points += amount;
	std::cout << GRN << _name << " has now " << _hit_points << " hit points." << RESET << std::endl;
}
