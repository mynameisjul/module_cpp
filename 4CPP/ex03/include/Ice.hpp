#ifndef ICE_HPP
#define ICE_HPP

#include "interface.h"

class Ice : public AMateria {
	public:
		// Member functions
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

		// Constructors and destructor
		Ice();
		Ice(Ice const &other);
		Ice &operator=(Ice const &other);
		~Ice();
};

#endif /* ICE_HPP */
