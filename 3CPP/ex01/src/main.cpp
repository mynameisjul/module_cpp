#include "ScavTrap.hpp"
#include "ClapTrap.hpp"

int main( void ) {
	ScavTrap a;
	ScavTrap b("ScavTrap B");
	ScavTrap c(b);
	ScavTrap d = a;
	ClapTrap e("ClapouTrapou");

	a.beRepaired(10);
	const std::string dName = "d";
	b.attack(dName);
	d.takeDamage(10);
	std::cout << "d has " << d.getHitPoints() << " hit points." << std::endl;
	a.attack("c");
	c.takeDamage(UINT32_MAX);
	b.beRepaired(UINT32_MAX);
	a.guardGate();
	//e.guardGate();
}
