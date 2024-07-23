#include "animal.h"

Animal::Animal() : _type("default") {
    std::cout << BGRN << "[Animal] Creating default animal" << RESET << std::endl;
}

Animal::Animal(std::string type) : _type(type) {
    std::cout << BGRN << "[Animal] Creating animal of type " << type << RESET << std::endl;
}

Animal::Animal(Animal const &other)
{
    std::cout << BGRN << "[Animal] Calling copy constructor with type " << _type << RESET << std::endl;
    *this = other;
}

Animal &Animal::operator=(Animal const &other)
{
    std::cout << BGRN << "[Animal] Calling copy assignement operator" << RESET << std::endl;
    if (this == &other)
        return (*this);
    _type = other._type;
    return (*this);
}

Animal::~Animal()
{
    std::cout << BRED << "[Animal] Destroying animal of type " << _type << RESET << std::endl;
}

// ========== MEMBER FUNCTIONS, GETTERS, SETTERS
void Animal::makeSound() const
{
    std::cout << "Generic animals do not make sounds" << std::endl;
}

std::string Animal::getType() const
{
    return (_type);
}

std::string *Animal::getIdeas() {
    return (0);
}

std::string Animal::getIdea(int index) {
    (void) index;
    return (0);
}

void Animal::setIdea(int index, std::string idea) {
    (void) index;
    (void) idea;
}