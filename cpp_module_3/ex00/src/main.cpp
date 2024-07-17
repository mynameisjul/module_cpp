#include "ClapTrap.hpp"

int main( void ) {
	ClapTrap a;
	ClapTrap b("ClapTrap B");
	ClapTrap c(b);
	ClapTrap d = b;

	a.beRepaired(10);
	const std::string dName = "d";
	b.attack(dName);
	d.takeDamage(10);
	std::cout << "d has " << d.getHitPoints() << " hit points." << std::endl;
	a.attack("c");
	c.takeDamage(UINT32_MAX);
	b.beRepaired(UINT32_MAX);
}
