#ifndef MATERIA_SOURCE_HPP
#define MATERIA_SOURCE_HPP

#include "interface.h"

class MateriaSource : public IMateriaSource {
	private:
		AMateria 		*_materias[4];
	public:
		// Member functions
		virtual void learnMateria(AMateria* other);
		virtual AMateria* createMateria(std::string const & type);
		// Constructor and destructors
		MateriaSource();
		MateriaSource(MateriaSource const &other);
		MateriaSource &operator=(MateriaSource const &other);
		~MateriaSource();
};

#endif /* MATERIA_SOURCE_HPP */
