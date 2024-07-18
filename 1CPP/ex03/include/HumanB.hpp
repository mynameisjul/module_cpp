#ifndef HUMANB_HPP
#define HUMANB_HPP

#include "Weapon.h"

class HumanB {
	private:
		std::string	_name;
		Weapon		*_weapon;

	public:
		HumanB(std::string name);
		~HumanB();
		void attack();
		void setWeapon(Weapon &weapon);
};

#endif