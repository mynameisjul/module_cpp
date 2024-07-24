#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "interface.h"
#include "AMateria.hpp"

class Character : public ICharacter {
	private:
		AMateria	*_inventory[4];
		std::string	_name;
	public:
		// Inherited functions
		virtual std::string const & getName() const;
		virtual void equip(AMateria* m);
		virtual void unequip(int idx);
		virtual void use(int idx, ICharacter& target);

		// Constructors and destructor
		Character();
		Character(std::string name);
		Character(Character const &other);
		Character &operator=(Character const &other);
		~Character();
};

#endif /* CHARACTER_HPP */
