#include "interface.h"

// Member functions
AMateria* Cure::clone() const {
	std::cout << "[Cure] Cloning a cure" << std::endl;
	Cure *newCure;

	newCure = new Cure();
	return (newCure);
}

void Cure::use(ICharacter& target) {
	std::cout << "[Cure] Cure: \"* heals " << target.getName() << "'s wound *\"" << std::endl;
}

// Constructors and destructor
Cure::Cure() : AMateria("cure") {
	std::cout << BGRN << "[Cure] Calling constructor" << RESET << std::endl;
}

Cure::Cure(Cure const &other) : AMateria(other) {
	std::cout << BGRN << "[Cure] Calling copy constructor" << RESET << std::endl;
}

Cure &Cure::operator=(Cure const &other) {
	std::cout << GRN << "[Cure] Calling copy assignement operator" << RESET << std::endl;
	if (this != &other)
		AMateria::operator=(other);
	return (*this);
}

Cure::~Cure() {
	std::cout << BRED << "[Cure] Calling destructor" << RESET << std::endl;
}