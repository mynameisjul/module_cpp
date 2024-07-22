#ifndef FRAG_TRAP_HPP
#define FRAG_TRAP_HPP

#include "ClapTrap.hpp"

class FragTrap: public ClapTrap {
	public:
		FragTrap();
		FragTrap(std::string name);
		FragTrap(FragTrap const &other);
		FragTrap & operator=(FragTrap const &other);
		~FragTrap();
		void highFivesGuys(void);
		virtual void	attack(const std::string& target);
};

#endif /* FRAG_TRAP_HPP */