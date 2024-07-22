#include "FragTrap.hpp"

// ========== CONSTRUCTORS AND DESTRUCTOR
FragTrap::FragTrap() : ClapTrap() {
	_energy_points = 100;
	_hit_points = 100;
	_attack_damage = 30;
	std::cout << BGRN << "### Creating random FragTrap..." << RESET << std::endl;
}

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
	_energy_points = 100;
	_hit_points = 100;
	_attack_damage = 30;
	std::cout << BGRN << "### Creating FragTrap named " << name << RESET << std::endl;
}

FragTrap::FragTrap(FragTrap const &other) : ClapTrap(other) {
	std::cout << BGRN << "### Calling copy constructor for FragTrap named " << _name << "..." << RESET << std::endl;
	*this = other;
	}

FragTrap & FragTrap::operator=(FragTrap const &other){
	std::cout << BGRN << "### Calling FragTrap copy assignment operator with name " << other._name << RESET << std::endl;
	if (this != &other)
	{
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

FragTrap::~FragTrap() {
	std::cout << BRED << "### Destroying FragTrap named " << _name << "..." << RESET << std::endl;
}

// ========== PUBLIC MEMBER FUNCTIONS

void FragTrap::highFivesGuys(void) {
	std::cout << "### " << " HIGH FIVES GUYS SO GOOOOOD TO SEE YAAAAh" << std::endl;
}

void FragTrap::attack(const std::string& target) {
	if (_energy_points < 1) {
		std::cout << RED << "No energy left to attack." << RESET << std::endl;
		return ;
	}
	if (_hit_points == 0) {
		std::cout << RED << "No hit points left to attack." << RESET << std::endl;
		return ;
	}
	_energy_points--;
	std::cout << YEL << "[FragTrap] " << _name << " is attacking " << target << RESET << std::endl;
}