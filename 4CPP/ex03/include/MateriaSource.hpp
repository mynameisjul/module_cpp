#ifndef MATERIASOURCE_HPP
#define MATERIASOURCE_HPP

#include "interface.h"

class MateriaSource {
	private:
		AMateria 		**_world_resources;
		unsigned int	_n_resources;
	public:
		// Member functions

		// Consstructor and destructors
		MateriaSource();
		~MateriaSource()
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /* MATERIASOURCE_HPP */
