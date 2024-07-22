#ifndef C90AEAC0_E70E_451E_BDE6_4D20ED7DC149
#define C90AEAC0_E70E_451E_BDE6_4D20ED7DC149
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
		virtual void	attack(const std::string& target);
};

#endif /* SCAV_TRAP_HPP */


#endif /* C90AEAC0_E70E_451E_BDE6_4D20ED7DC149 */
