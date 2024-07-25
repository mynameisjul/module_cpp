#include "interface.h"

// Member functions
AMateria* Ice::clone() const {
	std::cout << "[Ice] Cloning an ice" << RESET << std::endl;
	Ice *newIce;

	newIce = new Ice();
	return (newIce);
}

void Ice::use(ICharacter& target) {
	std::cout << "[Ice] Ice: \"* shoots an ice bolt at " << target.getName() << " *\"" << std::endl;
}

// Constructors and destructor
Ice::Ice() : AMateria("ice") {
	std::cout << BGRN << "[Ice]" << RESET << " Calling constructor" << RESET << std::endl;
}

Ice::Ice(Ice const &other) : AMateria(other) {
	std::cout << BGRN << "[Ice]" << RESET << " Calling copy constructor" << RESET << std::endl;
}

Ice &Ice::operator=(Ice const &other) {
	std::cout << GRN << "[Ice]" << RESET << " Calling copy assignement operator" << RESET << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Ice::~Ice() {
	std::cout << BRED << "[Ice]" << RESET << " Calling destructor" << RESET << std::endl;
}