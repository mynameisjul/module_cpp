#include "animal.h"

Dog::Dog() : Animal("Dog") {}

Dog::Dog(Dog const &other) : Animal(other)
{
    std::cout << BGRN << "[Dog] Calling copy constructor" << std::endl;
}

Dog &operator=(Dog const &other);
~Dog();
void makeSound() const;