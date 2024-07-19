#include "animal.h"

Dog::Dog() : Animal("Dog") {
    std::cout << BGRN << "[Dog 🐕] Calling constructor" << std::endl;
}

Dog::Dog(Dog const &other) : Animal(other)
{
    std::cout << BGRN << "[Dog 🐕] Calling copy constructor" << std::endl;
}

Dog & Dog::operator=(Dog const &other) {
    std::cout << GRN << "[Dog 🐕] Calling copy assignment operator" << RESET << std::endl;
    if (this != &other)
        Animal::operator=(other);
	return (*this);
}
Dog::~Dog() {
    std::cout << BRED << "[Dog 🐕] Destroying dog..." << RESET << std::endl;
}

void Dog::makeSound() const {
	std::cout << "[Dog 🐕] Woof!" << std::endl;
}
