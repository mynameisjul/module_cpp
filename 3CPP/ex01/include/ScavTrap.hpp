#ifndef SCAV_TRAP_HPP
#define SCAV_TRAP_HPP

#include "ClapTrap.hpp"

class ScavTrap: public ClapTrap {
	public:
		ScavTrap();
		ScavTrap(std::string name);
		ScavTrap(ScavTrap const &other);
		ScavTrap & operator=(ScavTrap const &other);
		~ScavTrap();
		void guardGate();
};

#endif /* SCAV_TRAP_HPP */
