#ifndef IMATERIA_SOURCE_HPP
#define IMATERIA_SOURCE_HPP

#include "interface.h"

class IMateriaSource
{
	public:
		virtual ~IMateriaSource() {}
		virtual void learnMateria(AMateria*) = 0;
		virtual AMateria* createMateria(std::string const & type) = 0;
};

#endif /* IMATERIA_SOURCE_HPP */
