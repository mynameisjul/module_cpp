#include "ScavTrap.hpp"

// ========== CONSTRUCTORS AND DESTRUCTOR
ScavTrap::ScavTrap() : ClapTrap() {
	_energy_points = 50;
	_hit_points = 100;
	_attack_damage = 20;
	std::cout << BGRN << "Creating random ScavTrap..." << RESET << std::endl;
}

ScavTrap::ScavTrap(std::string name) : ClapTrap(name) {
	_energy_points = 50;
	_hit_points = 100;
	_attack_damage = 20;
	std::cout << BGRN << "Creating ScavTrap named " << name << RESET << std::endl;
}

ScavTrap::ScavTrap(ScavTrap const &other) : ClapTrap(other) {
	*this = other;
	std::cout << BGRN << "Calling copy constructor for ScavTrap named " << _name << "..." << RESET << std::endl;
}

ScavTrap & ScavTrap::operator=(ScavTrap const &other){
	if (*this != &other)
	{
		_name = other._name;
		_hit_points = other._hit_points;
		_energy_points = other._energy_points;
		_attack_damage = other._attack_damage;
	}
	return (*this);
}

ScavTrap::~ScavTrap(){
	std::cout << BRED << "Destroying ScavTrap named " << _name << "..." << RESET << std::endl;
}

// ========== PUBLIC MEMBER FUNCTIONS

void ScavTrap::guardGate() {
	std::cout << _name << " is now in Gate keeper mode." << std::endl;
}
