#ifndef AMATERIA_HPP
#define AMATERIA_HPP

#include "interface.h"
#include "ICharacter.hpp"

class AMateria {
	protected:
		std::string _type;
	public:
		// Member functions
		virtual AMateria* clone() const = 0;
		virtual void use(ICharacter& target);

		// Getters and setters
		std::string const & getType() const; //Returns the materia type
		
		// Constructors and destructor
		AMateria(std::string const &type);
		AMateria(AMateria const &other);
		AMateria &operator=(AMateria const &other);
		virtual ~AMateria();
};

#endif /* AMATERIA_HPP */
