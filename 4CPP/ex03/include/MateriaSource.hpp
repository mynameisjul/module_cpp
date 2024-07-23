#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "interface.h"

class MateriaSource {
	private:
		AMateria 		*_materias[4];
	public:
		// Member functions

		// Consstructor and destructors
		MateriaSource();
		~MateriaSource()
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /* MATERIA_SOURCE_HPP */
