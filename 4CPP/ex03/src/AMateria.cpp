#include "interface.h"

// Member functions are all virtual
void AMateria::use(ICharacter& target) {
	(void) target;
}
		
// Getters and setters
std::string const & AMateria::getType() const {
	return (_type);
} //Returns the materia type
		
// Constructors and destructor
AMateria::AMateria(std::string const &type) {
	std::cout << BGRN << "[AMateria] Calling constructor" << RESET << std::endl;
	_type = type;
}

AMateria::AMateria(AMateria const &other) {
	std::cout << BGRN << "[AMateria] Calling copy constructor" << RESET << std::endl;
	*this = other;
}

AMateria & AMateria::operator=(AMateria const &other) {
	std::cout << GRN << "[AMateria] Calling copy assignment operator" << RESET << std::endl;
	_type = other._type;
	return (*this);
}
AMateria::~AMateria() {
	std::cout << BRED << "[AMateria] Calling destructor" << RESET << std::endl;
}