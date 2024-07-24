#ifndef CURE_HPP
#define CURE_HPP

#include "interface.h"

class Cure : public AMateria {
	public:
		// Member functions
		virtual AMateria* clone() const;
		virtual void use(ICharacter& target);

		// Constructors and destructor
		Cure();
		Cure(Cure const &other);
		Cure &operator=(Cure const &other);
		~Cure();
};

#endif /* CURE_HPP */
