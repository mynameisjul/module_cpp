#include "ScavTrap.hpp"
#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main( void ) {
	ClapTrap a;
	ScavTrap b("ScavTrap B");
	ScavTrap c(b);
	ClapTrap e("ClapouTrapou");
	FragTrap f("FragouTrapou");

	a.beRepaired(10);
	b.attack("a");
	f.attack("Coucou");
	a.takeDamage(20);
	std::cout << "a has " << a.getHitPoints() << " hit points." << std::endl;
	a.attack("c");
	c.takeDamage(UINT32_MAX);
	b.beRepaired(UINT32_MAX);
	b.guardGate();
	f.highFivesGuys();
	//e.guardGate();
	//e.highFivesGuys;
}
