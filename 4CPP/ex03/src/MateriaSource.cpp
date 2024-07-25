#include "interface.h"

// Member functions
void MateriaSource::learnMateria(AMateria* other) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] == 0) {
			_materias[i] = other;
			return;
		}
	}
	std::cout << RED << "[MateriaSource]" << RESET << " Could not learn materia: memory is full" << RESET << std::endl;
}

AMateria* MateriaSource::createMateria(std::string const & type) {
	for (int i = 0; i < 4; i++) {
		if (_materias[i] && _materias[i]->getType() == type)
			return (_materias[i]->clone());
	}
	std::cout << RED << "[MateriaSource]" << RESET << "Could not create materia: materia is not in stock" << RESET << std::endl;
	return (0);
}

// Constructor and destructors
MateriaSource::MateriaSource() {
	std::cout << BGRN << "[MateriaSource]" << RESET << " Calling default constructor" << RESET << std::endl;
	for (int i = 0; i < 4; i++)
		_materias[i] = 0;
}

MateriaSource::MateriaSource(MateriaSource const &other) {
	std::cout << BGRN << "[MateriaSource]" << RESET << " Calling copy constructor" << RESET << std::endl;
	*this = other;
}

MateriaSource & MateriaSource::operator=(MateriaSource const &other) {
	std::cout << GRN << "[MateriaSource]" << RESET << " Calling copy assignement operator" << RESET << std::endl;
	if (this != &other) {
		for (int i = 0; i < 4; i++) {
			if (_materias[i])
				delete _materias[i];
			if (other._materias[i])
				_materias[i] = other._materias[i]->clone();
		}
	}
	return (*this);
}

MateriaSource::~MateriaSource() {
	std::cout << BRED << "[MateriaSource]" << RESET << " Calling destructor" << RESET << std::endl;
	for (int i = 0; i <  4; i++) {
		if (_materias[i])
			delete _materias[i];
	}
}